class Solution {
public:

    // one bouqet = k adjacent flowers

    // it says after day days , how many flowers we can make from the garden
    int f(int day ,  int k , vector<int> &b){
        int total =0;
        int curr=0;

        for(int i=0;i<b.size();i++){
            bool stat = day>=b[i];

            if(stat){
                if(i==0){
                    curr++;
                }
                else if( day>=b[i-1] ){
                    curr++;
                }
                else{
                    curr=1;
                }

                if(curr==k){
                    curr=0;
                    total++;
                }
            }
            else{
                curr=0;
            }

        }

        return total;
        
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > (long long)n) return -1;
        int maxi = INT_MAX;
        for(auto it : bloomDay) maxi = max(maxi , it);
        int low = 1 , high = maxi;

        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(f(mid , k , bloomDay)>=m){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;



        }

        return ans;

    }
};