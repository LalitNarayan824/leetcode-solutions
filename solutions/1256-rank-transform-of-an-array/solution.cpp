class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int , int> mp;
        int rank=1 , n = arr.size() ;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        for(auto it : temp){
            if(mp.count(it)==0) mp[it]=rank++;
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i] = mp[arr[i]];
        }

        return ans;
        
    }
};