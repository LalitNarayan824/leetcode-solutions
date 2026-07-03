#!/usr/bin/env python3
"""
LeetCode -> GitHub auto-sync.

Polls LeetCode's (unofficial) GraphQL API for your recently accepted
submissions, and writes any new ones to disk as files, ready to be
committed by the surrounding GitHub Actions workflow.

Required environment variables:
  LEETCODE_SESSION   - value of the `LEETCODE_SESSION` cookie from leetcode.com
  LEETCODE_CSRF      - value of the `csrftoken` cookie from leetcode.com
  SOLUTIONS_DIR      - (optional) directory to write solutions into, default "solutions"
  STATE_FILE         - (optional) path to the JSON file tracking already-synced
                        submissions, default "synced.json"
"""

import json
import os
import sys
import time
from pathlib import Path

import requests

LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"

# Maps LeetCode's internal language names to file extensions.
LANG_EXTENSIONS = {
    "python3": "py",
    "python": "py",
    "java": "java",
    "cpp": "cpp",
    "c": "c",
    "csharp": "cs",
    "javascript": "js",
    "typescript": "ts",
    "golang": "go",
    "kotlin": "kt",
    "swift": "swift",
    "rust": "rs",
    "ruby": "rb",
    "scala": "scala",
    "php": "php",
    "erlang": "erl",
    "elixir": "ex",
    "racket": "rkt",
    "dart": "dart",
    "mysql": "sql",
    "mssql": "sql",
    "oraclesql": "sql",
}

SUBMISSIONS_QUERY = """
query recentAcSubmissions($username: String!, $limit: Int!) {
  recentAcSubmissionList(username: $username, limit: $limit) {
    id
    title
    titleSlug
    timestamp
    lang
  }
}
"""

SUBMISSION_DETAIL_QUERY = """
query submissionDetails($submissionId: Int!) {
  submissionDetails(submissionId: $submissionId) {
    code
    lang {
      name
    }
    question {
      questionId
      title
      titleSlug
      difficulty
    }
  }
}
"""


def get_session():
    """Build a requests session authenticated as the logged-in LeetCode user."""
    leetcode_session = os.environ.get("LEETCODE_SESSION")
    csrf_token = os.environ.get("LEETCODE_CSRF")

    if not leetcode_session or not csrf_token:
        sys.exit(
            "ERROR: LEETCODE_SESSION and LEETCODE_CSRF environment variables "
            "must both be set."
        )

    session = requests.Session()
    session.cookies.set("LEETCODE_SESSION", leetcode_session, domain="leetcode.com")
    session.cookies.set("csrftoken", csrf_token, domain="leetcode.com")
    session.headers.update(
        {
            "Content-Type": "application/json",
            "Referer": "https://leetcode.com",
            "x-csrftoken": csrf_token,
            "User-Agent": "Mozilla/5.0 (leetcode-sync script)",
        }
    )
    return session


def get_username(session):
    query = """
    query globalData {
      userStatus {
        username
        isSignedIn
      }
    }
    """
    resp = session.post(LEETCODE_GRAPHQL_URL, json={"query": query})
    resp.raise_for_status()
    data = resp.json()["data"]["userStatus"]
    if not data.get("isSignedIn"):
        sys.exit(
            "ERROR: Not signed in - your LEETCODE_SESSION / LEETCODE_CSRF "
            "cookies are likely expired. Refresh them and update the secrets."
        )
    return data["username"]


def fetch_recent_accepted(session, username, limit=20):
    resp = session.post(
        LEETCODE_GRAPHQL_URL,
        json={
            "query": SUBMISSIONS_QUERY,
            "variables": {"username": username, "limit": limit},
        },
    )
    resp.raise_for_status()
    return resp.json()["data"]["recentAcSubmissionList"]


def fetch_submission_detail(session, submission_id):
    resp = session.post(
        LEETCODE_GRAPHQL_URL,
        json={
            "query": SUBMISSION_DETAIL_QUERY,
            "variables": {"submissionId": int(submission_id)},
        },
    )
    resp.raise_for_status()
    payload = resp.json()
    return payload.get("data", {}).get("submissionDetails")


def load_state(state_file):
    if Path(state_file).exists():
        with open(state_file) as f:
            return json.load(f)
    return {"synced_ids": []}


def save_state(state_file, state):
    with open(state_file, "w") as f:
        json.dump(state, f, indent=2)


def slugify_folder(question_id, title_slug):
    return f"{question_id}-{title_slug}"


def main():
    solutions_dir = Path(os.environ.get("SOLUTIONS_DIR", "solutions"))
    state_file = os.environ.get("STATE_FILE", "synced.json")

    solutions_dir.mkdir(parents=True, exist_ok=True)
    state = load_state(state_file)
    synced_ids = set(state["synced_ids"])

    session = get_session()
    username = get_username(session)
    print(f"Signed in as: {username}")

    recent = fetch_recent_accepted(session, username, limit=20)
    print(f"Fetched {len(recent)} recent accepted submissions")

    new_count = 0

    for submission in recent:
        sub_id = submission["id"]
        if sub_id in synced_ids:
            continue

        detail = fetch_submission_detail(session, sub_id)
        if not detail:
            print(f"  Skipping {sub_id} ({submission['title']}) - no detail returned")
            continue

        question = detail["question"]
        lang_name = detail["lang"]["name"]
        ext = LANG_EXTENSIONS.get(lang_name.lower(), "txt")

        folder = solutions_dir / slugify_folder(
            question["questionId"], question["titleSlug"]
        )
        folder.mkdir(parents=True, exist_ok=True)

        code_file = folder / f"solution.{ext}"
        code_file.write_text(detail["code"])

        readme_file = folder / "README.md"
        readme_file.write_text(
            f"# {question['questionId']}. {question['title']}\n\n"
            f"Difficulty: {question['difficulty']}\n\n"
            f"Language: {lang_name}\n\n"
            f"Link: https://leetcode.com/problems/{question['titleSlug']}/\n"
        )

        synced_ids.add(sub_id)
        new_count += 1
        print(f"  Synced: {question['title']} ({lang_name})")

        # Be polite to LeetCode's API between detail requests
        time.sleep(1)

    state["synced_ids"] = list(synced_ids)
    save_state(state_file, state)

    print(f"Done. {new_count} new solution(s) synced.")

    # Emit for the GitHub Actions workflow to know whether to commit.
    github_output = os.environ.get("GITHUB_OUTPUT")
    if github_output:
        with open(github_output, "a") as f:
            f.write(f"new_count={new_count}\n")


if __name__ == "__main__":
    main()
