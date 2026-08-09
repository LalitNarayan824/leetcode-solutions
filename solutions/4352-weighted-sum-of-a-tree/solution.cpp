class Solution {
public:


    int dfsHeight(int node, const vector<vector<int>>& tree) {
    int height = 0;
    for (int child : tree[node]) {
        height = max(height, dfsHeight(child, tree));
    }
    return height + 1; // +1 for current node
}
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> g(n);

        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
                g[parent[i]].push_back(i);
            }
        }
        int h = dfsHeight(0 , g);

        queue<int> q;
        vector<bool> vis(n, 0);

        q.push(0);
        int d = 1;
        long long ans =0 ;
        vis[0]=1;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int node = q.front();q.pop();
                ans+= ((long long)nums[node] *(long long)(h-d+1));

                for(auto nbr : g[node]){
                    if(!vis[nbr]){
                       q.push(nbr);
                        vis[nbr]=1;
                    }
                }
            }
                d++;
            
        }

        return ans;
    }
};