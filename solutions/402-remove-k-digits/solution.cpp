class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for( int i=0;i<n;i++ ){

            while( !st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();k--;
            }

            st.push(num[i]);


        }

        while(k--){
            st.pop();
        }

        // k>n k==n
        if(st.empty()) return "0";

        // building the number
        string ans ="";

        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }

        reverse(ans.begin(), ans.end());
        int m = ans.size();
        int index =0 ;
        while(ans[index]=='0') index++;

        if(index==m) return "0";


        return ans.substr(index);
    }
};