class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans ;
        int dis = INT_MAX;

        for(auto &it : nums){
            if(abs(it)<dis){
                dis = abs(it);
                ans = it;
            }
            else if(abs(it)==dis && it>ans ) ans = it;
        }

        return ans;
    }
};