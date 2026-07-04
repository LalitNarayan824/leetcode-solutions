# LeetCode → GitHub Auto-Sync

Automatically syncs your accepted LeetCode submissions to this repo, every 6
hours, using a scheduled GitHub Actions workflow. No third-party extension,
no broad GitHub permissions, no server to host. Commits are authored under
your own GitHub identity, so they count toward your contribution graph.

## Why this is safe

- Runs entirely inside **your own repo's GitHub Actions**, using the
  repo-scoped built-in `GITHUB_TOKEN` — it can only write to *this* repo,
  nothing else.
- Commits are made under your own GitHub username and noreply email (not a
  generic bot identity), so they show up as your contributions.
- Your LeetCode session is stored as an encrypted **repository secret**,
  never exposed in logs or to any third party.
- All code is here for you to read — nothing is a black box.

## Setup

### 1. Get your LeetCode session cookies

1. Log into [leetcode.com](https://leetcode.com) in your browser.
2. Open DevTools → Application (Chrome) / Storage (Firefox) → Cookies →
   `https://leetcode.com`.
3. Copy the values of these two cookies:
   - `LEETCODE_SESSION`
   - `csrftoken`

These cookies expire periodically (LeetCode doesn't publish an exact TTL —
often several weeks), so you may need to refresh them occasionally if the
workflow starts failing with a "not signed in" error.

### 2. Create the GitHub repo

Create a new repo (or use an existing one) where you want your solutions
stored, and push these files (`sync.py`, `.github/workflows/leetcode-sync.yml`,
`requirements` are installed inline in the workflow) to it.

### 3. Add repo secrets

In your repo: **Settings → Secrets and variables → Actions → New repository
secret**, and add:

| Name               | Value                          |
|--------------------|---------------------------------|
| `LEETCODE_SESSION` | value of the `LEETCODE_SESSION` cookie |
| `LEETCODE_CSRF`    | value of the `csrftoken` cookie |

No GitHub token needs to be added manually — the workflow uses the
automatically-provided `GITHUB_TOKEN`, scoped only to this repo.

### 4. Enable Actions & test it

1. Go to the **Actions** tab of your repo, enable workflows if prompted.
2. Click into "LeetCode Sync" → **Run workflow** to trigger it manually the
   first time and confirm it works.
3. After that, it'll run automatically every 6 hours via the cron
   schedule, and only commit when there's something new to sync.

## How it works

1. `sync.py` authenticates to LeetCode's GraphQL API using your session
   cookies.
2. It fetches your ~20 most recent accepted submissions.
3. It compares them against `synced.json` (a small state file it maintains
   in the repo) to figure out which ones are new.
4. For each new one, it fetches the full submission code + metadata and
   writes it to `solutions/{questionId}-{titleSlug}/solution.{ext}` plus a
   `README.md` with problem info.
5. The GitHub Actions workflow commits and pushes any new files.

## Notes / limitations

- Not instant — solutions show up within 6 hours (or less, depending on
  when in the cycle you solved it). You can lower the cron interval (e.g.
  `0 */6 * * *` → `*/30 * * * *` for every 30 minutes) if you want it
  tighter, keeping in mind GitHub Actions free-tier minute limits.
- LeetCode's GraphQL API is unofficial/undocumented, so it could change
  without notice — if the workflow starts failing, check LeetCode hasn't
  altered the schema.
- Only your last ~20 accepted submissions are checked each run. If you
  solve more than 20 problems within a single 6-hour window, older ones
  could be missed — unlikely for normal usage, but worth knowing.
