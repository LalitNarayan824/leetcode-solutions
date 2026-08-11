class Solution {
public:


    int f(int cap , vector<int> & w){
        int days =0;

        int curr=0;

        for(auto &it : w){
            if(curr + it>cap){
                days++;
                curr = it;
            }
            else curr += it;
        }

        return days + (curr + cap-1)/cap;


    }


    int shipWithinDays(vector<int>& weights, int days) {
        int sum =0;
        for(auto &it : weights) sum+=it;
        int maxi = INT_MIN;
        for(auto &it : weights) maxi = max(maxi , it);
        int low = maxi , high = sum;

        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(f(mid, weights)<=days){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;



    }
};