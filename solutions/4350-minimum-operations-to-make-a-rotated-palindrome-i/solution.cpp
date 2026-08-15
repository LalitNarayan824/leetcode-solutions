class Solution {
public:
    int minOperations(string st) {
        int ans = INT_MAX;

        int n = st.size();

        // left rotate n-1 times
        for(int i=1;i<=n;i++){
            int cnt = i-1;
            int s = 0 , e = n-1;

            while(s<e){
                cnt += min(  abs(st[s]- st[e]) , 26 - abs(st[s]-st[e]) );
                s++;
                e--;
                
            }


            // cout<<i-1<<" "<<st<<" "<<cnt<<endl;
            ans = min(ans , cnt);
            

            char start = st[0];
            st = st.substr(1)+start;

            
        }

        return ans;

        
        
    }
};