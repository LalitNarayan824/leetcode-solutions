class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0 , e=nums.size()-1;

        int ans =-1;
        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid]==target){
                ans = mid ;
                break;
            }
            else if( nums[mid] < target) s = mid+1;
            else e = mid-1;


        }

        return ans;
    }
};