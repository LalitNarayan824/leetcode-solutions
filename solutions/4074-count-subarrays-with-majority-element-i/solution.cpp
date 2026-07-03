class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans =0 , frq =0 ;
        int n = nums.size();

        for(int i=0;i<n;i++){
            frq=0;
            for(int j=i;j<n;j++){
                // len = j-i+1

                if(nums[j]==target) frq++;

                if(frq > (j-i+1)/2) ans++;
            }

        }   

        return ans;
    }
};