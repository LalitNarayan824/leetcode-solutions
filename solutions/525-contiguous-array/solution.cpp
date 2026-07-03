class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n , 0);

        pre[0] = nums[0] == 1 ? 1 : -1;

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + (nums[i]==1?1:-1);
        }

        unordered_map<int , int> sums; // sum -> index

        int ans = 0;

        for(int i=0;i<n;i++){
            
            if(sums.contains(pre[i])){
                ans = max(ans , i- sums[pre[i]]);
            }
            else sums[pre[i]]=i;

            if(pre[i]==0) ans = max(ans , i+1);
        }

        return ans;

    }
};