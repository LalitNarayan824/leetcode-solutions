class Solution {
public:

    void dfs(int u , vector<bool> &vis , vector<vector<int>> &adj , vector<int> &temp){
        if(vis[u]) return;
        vis[u] =1;
        temp[0]++;

        for(int v : adj[u]){
            temp[1]++;
            if(vis[v]==0) dfs(v , vis , adj , temp);

        }


    }



    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto & edge :edges){
            int u = edge[0], v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=0;
        vector<bool> vis( n , 0);
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                temp={0 , 0};
                dfs(i , vis , adj , temp);
                int v = temp[0] , cnt = temp[1];
                cnt = cnt/2;

                if(   (v *(v-1))/2 == cnt ) ans++;
            }


        }

        return ans;




    }
};