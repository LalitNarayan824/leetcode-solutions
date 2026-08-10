class Solution {
public:

    int f(vector<int> &arr , int target){
        int low = 0, high = arr.size() - 1;
        // int ans ;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return mid;

            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
            }

        return low;
    }

    int g(vector<int> &arr , int target){
        int n = arr.size();
        if(target > arr[n-1]) return n;
        if(target < arr[0]) return 0;

        int ans ;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > target) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return ans;
    }

    


    int searchInsert(vector<int>& nums, int target) {
        // return the index if found
        return  f(nums , target);

        
        // return index of el just greater than the target 

    }
};