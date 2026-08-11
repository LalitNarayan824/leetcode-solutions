class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]+1){
                sum+=nums[i];
            }
            else break;
        }
        sort(nums.begin(), nums.end());

        while(true){
            int idx = lower_bound(nums.begin(), nums.end(), sum) - nums.begin();

            if(idx == nums.size() || nums[idx]!=sum) return sum;

            sum++;


        }
        return 0;

    }
};