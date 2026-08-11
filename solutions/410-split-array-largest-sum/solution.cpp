class Solution {
public:

    // returns the minimum number of subarrays into which we can split the nums such that max subarray sum <= limit
    int f(int limit , vector<int> &nums){
        int tot =1;

        int curr=0;

        for(auto it : nums){
            if(curr+it<=limit){
                curr+=it;
            }
            else{
                tot++;
                curr = it;
            }


        }

        return tot;

    }

    

    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(auto &it : nums) high += it;

        int ans = low;

        while(low<=high){
            int mid = low + (high-low)/2;

            if( f(mid , nums) <= k ){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;



    }
};