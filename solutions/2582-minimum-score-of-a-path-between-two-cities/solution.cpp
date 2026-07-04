class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> g(n+1);

        for(auto &it : roads){
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }


        vector<bool> vis(n+1 , 0);

        int min_edge = INT_MAX;

        queue<int> q;
        q.push(1);
        vis[1]=1;

        while(!q.empty()){
            int node = q.front();q.pop();

            for(auto &t : g[node]){
                int nbr = t[0], dist = t[1];
                min_edge = min(min_edge , dist);
                if(!vis[nbr]){  
                    q.push(nbr);
                    vis[nbr]=1;
                }
            }
        }

        return min_edge;
    }
};