class Solution {
public:
    int n ;
    vector<vector<pair<int,int>>> g;   // changed to pair<int,int> but same meaning
    const long long INF = 1e18;        // safer INF

    bool f(int min_edge , long long k){

        vector<long long> dist(n , INF);
        dist[0]=0;

        // curr_dist , node
        priority_queue< pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>> > pq;

        pq.push({0 , 0});

        while(!pq.empty()){
            auto t = pq.top();pq.pop();
            long long curr = t.first , node = t.second;
            if(curr > dist[node]) continue;

            for(auto &temp : g[node]){
                long long v = temp.first , w = temp.second;

                // every edge should be >= min_edge
                if( w>=min_edge && (dist[node]+w < dist[v] )){
                    dist[v] = dist[node]+w;

                    pq.push({dist[v], v});
                }
            }
        }

        // if dist is INF or >k then false
        if(dist[n-1]==INF || dist[n-1]>k ) return 0;
        return 1;
    }


    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        // first build the graph and find max edge cost
        n = online.size();
        unordered_set<int> offline;
        int max_edge_cost = -1;

        g = vector<vector<pair<int,int>>>(n);

        for(int i=0;i<n;i++){
            if(online[i]==false) offline.insert(i);
        }

        // node -> [ { v , w }, ...  ]
        // both u and v needs to be online
        for( auto &edge : edges ){
            int u = edge[0], v = edge[1], w= edge[2];
            if(offline.count(u)==0 && offline.count(v)==0){

                g[u].push_back({v, w});
                max_edge_cost = max(max_edge_cost , w);   // conserve your logic
            }
        }

        // if no valid edges
        if(max_edge_cost < 0) return -1;

        // we BS for every posbl min value of edge and find the max posbl from it
        int s=0 , e=max_edge_cost;

        int ans = INT_MAX;

        while(s<=e){
            int mid = s + (e-s)/2;

            // we run djikstra with a condition that every edge should be >= mid ,
            // and min cost to n-1th node is less than <=k , then its true for the mid value
            // we take it as ans and we can move to a bigger value or if false ,we move to a smaller value

            if(f(mid , k)){
                ans = mid;
                s=mid+1;
            }
            else e = mid-1;
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};
