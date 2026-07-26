class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> pos , neg;

        for(auto &it : nums){
            if(it>=0) pos.push_back(it);
            else neg.push_back(it);
        }


        sort(pos.begin(), pos.end(), [](int a , int b){
            return a>b;
        });

        sort(neg.begin(), neg.end());

        // first two from neg & first one from pos

        // all frist three from pos

        int maxi = INT_MIN;

        if(pos.size()==0){
            int n = neg.size();
            return neg[n-1]*neg[n-2]*neg[n-3];
        }

        if(neg.size()>=2 && pos.size()>=1){
            maxi = max(maxi , neg[0]*neg[1]*pos[0]);
        }

        if(pos.size()>=3){
            maxi = max(maxi , pos[0]*pos[1]*pos[2]);
        }

        return maxi;
    }

};