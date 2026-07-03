class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<unsigned long long , int> f;


        for(auto & it : nums){
            f[it]++;
        }


        // aasssuming each it as x

        int ans = 1;
        for(auto &it : nums){
            unsigned long long x = it;
            int len =0;

            while(true){
                
                if(x==1) break;
                if(f.find(x)==f.end()){
                    len = len*2 -1;
                    break;
                }


                if(f[x]>=2){
                    len+=1;
                }
                else if(f[x]==1){
                    
                    len = len*2;
                    len++;

                    break;
                }

                x = x*x;


            }

            ans = max(ans , len);
        }


        if(f.find(1)!=f.end()){
            int l = f[1];
            if(l%2==0) l--;
            ans = max(ans , l);
        }


        return ans;
    }
};