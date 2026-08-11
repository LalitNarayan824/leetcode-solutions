class Solution {
public:

    
    long long f(int k , vector<int> &piles){

        long long ans =0;
        for(auto it : piles){
            // long long temp = it%k==0 ? it/k : (it/k)+1;
            // ans += temp;
            ans += (it+k-1)/k;
        }


        return ans;



    }


    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi = INT_MIN;
        for(auto &it : piles) maxi = max(maxi , it);

        // range = 1 to maxi

        int low = 1 , high = maxi;
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(f(mid, piles)<=(long long)h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};