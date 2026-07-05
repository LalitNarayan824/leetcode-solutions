class Solution {
public:
const long long MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<long long>> max_score(n, vector<long long>(n, -1));
        vector<vector<long long>> ways(n, vector<long long>(n, 0));

        // Treat S and E as 0
        board[0][0] = '0';
        board[n-1][n-1] = '0';

        // Start at S
        max_score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        // Main DP loop
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                if(board[i][j] == 'X') continue;
                if(i == n-1 && j == n-1) continue;

                long long best = -1;
                long long count = 0;

                // check down-left (i+1, j+1)
                if(i+1<n && j+1<n){
                    if(max_score[i+1][j+1]> best){
                        best = max_score[i+1][j+1];
                        count = ways[i+1][j+1];
                    }
                    else if(max_score[i+1][j+1]==best){
                        count = (count + ways[i+1][j+1]) % MOD;

                    }
                }
                // check down (i+1, j)
                if(i+1<n){
                    if(max_score[i+1][j]> best){
                        best = max_score[i+1][j];
                        count = ways[i+1][j];
                    }
                    else if(max_score[i+1][j]==best){
                        count = (count + ways[i+1][j]) % MOD;

                    }
                }


                // check right (i, j+1)
                if(j+1<n){
                    if(max_score[i][j+1]> best){
                        best = max_score[i][j+1];
                        count = ways[i][j+1];
                    }
                    else if(max_score[i][j+1]==best){
                        count = (count + ways[i][j+1]) % MOD;

                    }
                }
                // YOU will fill these three checks

                if(best != -1) {
                    max_score[i][j] = best + (board[i][j] - '0');
                    ways[i][j] = count % MOD;
                }
            }
        }

        if(max_score[0][0] < 0) return {0, 0};
        return {(int)max_score[0][0], (int)(ways[0][0] % MOD)};
    }
};

// kimi omou koi

// kumerashi guberashi


