class Solution {
public:
    int numSquares(int n) {
        vector<int> psq;

        for(int i=1;i<=n;i++){
            if(i*i<=n) psq.push_back(i*i);
            else break;
        }

        vector<int> dp(n+1 , 0);

        dp[1]=1;

        for(int i=2;i<=n;i++){
            int ans = INT_MAX;
            for(auto it : psq){
                if(i-it>=0) ans = min(ans , dp[i-it]+1);
            }

            dp[i] = ans;


        }

        return dp[n];
    }
};