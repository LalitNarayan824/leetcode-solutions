class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() , n = grid[0].size();


        // we have m*n nodes
        vector<vector<vector<int>>> g(m*n);

        //dirs vector
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0},{-1, 0}};
        
        //building the graph 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int src = i*n + j;
                for(auto &dir : dirs){
                    int x = i+dir[0] , y = j+dir[1];

                    if(x>=0 && x<m && y>=0 && y<n){
                        // [i,j]--->[x,y]
                        int dest = x*n + y;

                        if(grid[x][y]==1){
                            // g[src][dest]=1;
                            g[src].push_back({dest , 1});
                        }
                        else{
                            g[src].push_back({dest , 0});

                        }
                    }
                }


            }
        }


        // we just have to apply dijkstra now

        vector<int> dist(m*n , INT_MAX);
        dist[0]=0;

        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>> > pq;
        pq.push({0 , 0});
        // dist , node 
        // node == 0 as src bec [0 , 0]

        while(!pq.empty()){
            auto t = pq.top();pq.pop();
            int u = t[1] , curr = t[0];
            if( curr > dist[u] ) continue;

            for(auto edge : g[u]){
                int v = edge[0], w = edge[1];
                if( dist[u] + w < dist[v] ){
                    dist[v] = dist[u] +w;
                    pq.push({dist[v], v});
                }
            }

        }



        int minimum = dist[m*n-1];

        if(grid[0][0]) minimum++;

        // cout<<minimum;

        return health > minimum;






        
    }
};

// think of it like  1 , 0 are points on the board , you need to get from the src to dest with min points psbll ,then we check from the health if we are under radar

// make a graph and find min path from src to dest