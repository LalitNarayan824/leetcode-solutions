class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int tot = 0;
        for(auto it : stones){
            tot+=it;
        }

        vector<bool> dp( tot+1 , 0);

        dp[0]=1;

        for(int w : stones){
            for(int tar = tot ; tar >= w ; tar--){
                if(dp[tar-w]) dp[tar]=1;
            }
        }

        for (int s = tot/2; s >= 0; s--) {
    if (dp[s]) return tot - 2*s;
}


        return 0;


    }
};