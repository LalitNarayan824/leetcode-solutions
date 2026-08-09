class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // int ans = 0;
        stack<int> st;
        string ans ="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
               
            }
            else if(s[i]==')'){
                // its a closing bracket
                if(st.empty()){
                    s[i]='!';
                }
                else st.pop();
                

            }
            
        }

        while(!st.empty()){
            s[st.top()]='!';
            st.pop();
            
        }

        for(auto it : s){
            if(it!='!') ans+= it;
        }
        return ans ;
    }
};