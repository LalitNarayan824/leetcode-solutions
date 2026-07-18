class TreeAncestor {
public:

    int LOG;
    vector<vector<int>> up;

    TreeAncestor(int n, vector<int>& parent) {
        LOG=0;
        while((1<<LOG)<=n) LOG++;

        up.assign(n , vector<int>(LOG , -1));

        for(int i=0;i<n;i++){
            up[i][0] = parent[i];
        }

        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                int mid = up[i][k-1];
                if(mid!=-1){
                    up[i][k] = up[mid][k-1];
                }
                else{
                    up[i][k]=-1;
                }
            }
        }


    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<LOG;i++){
            if(node==-1) break;

            if(k&(1<<i)){
                node = up[node][i];
            }
        }

        return node;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */