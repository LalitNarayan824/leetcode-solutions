class Solution {
public:
    string removeDuplicates(string s) {
        int n= s.size();
        stack<char> st;

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);continue;
            }

            if(s[i] == st.top()){
                st.pop();continue;
            }

            st.push(s[i]);
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};