class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // we need vector of edges

        // for this we can iterate over nums and directly look at the edges
        // do DSU
        // answer the queries
        // we will do something very interesting 

        // we will label every node with the componenet label directly 

        vector<int> labels(n);
        int label=1;

        labels[0]=label;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff) labels[i] = label;
            else{
                label++;
                labels[i] = label;
            }
        }


        int m = queries.size();
        vector<bool> ans(m);

        for(int i=0;i<m;i++){
            if(labels[queries[i][0]] == labels[queries[i][1]]) ans[i] = true;
            else ans[i] = false;
        }

        return ans;
    }
};