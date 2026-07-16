class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size() , maxi = -1;

        vector<int> prefixGcd;

        for(auto it : nums){
            maxi = max(maxi , it);
            prefixGcd.push_back(gcd(it , maxi));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int s=0 , e=n-1;
        long long ans=0;
        while(s<e){
            ans+= gcd(prefixGcd[s++] ,prefixGcd[e--]);
        }

        return ans;
    }
};