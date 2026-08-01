class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n , 0));



        for(int i=0;i<n;i++) dp[i][i] = nums[i];


        for(int diff=1;diff<n;diff++){
            for(int i=0;i<n && (i+diff)<n;i++){
                int j = i+diff;

                dp[i][j] = max( nums[i] - dp[i+1][j] , nums[j] - dp[i][j-1] );
            }
        }

        return dp[0][n-1]>=0;
    }
};