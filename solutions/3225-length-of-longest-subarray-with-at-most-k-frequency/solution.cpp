class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l =0 , ans = -1, n = nums.size(), r;

        unordered_map<int, int> mp;

        for(r=0;r<n;r++){

            if(mp.find(nums[r])==mp.end()){
                mp[nums[r]]=1;
            }
            else{
                if(mp[nums[r]]<k){
                    mp[nums[r]]++;
                }
                else{
                    while(nums[l]!=nums[r]){
                        mp[nums[l]]--;
                        if(mp[nums[l]]==0) mp.erase(nums[l]);
                        l++;
                    }

                    l++;

                }
                
            }

            ans = max(ans , r-l+1);







        }

        // ans = max(ans , r-l+1);

        return ans;
    }
};