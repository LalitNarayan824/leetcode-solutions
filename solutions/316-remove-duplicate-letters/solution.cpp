class Solution {
public:
    string removeDuplicateLetters(string s) {
        // last index
        // stack
        int n = s.size();
        vector<int> last(26, -1);
        vector<bool> taken(26, 0);
        stack<char> st;

        // init last index
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }


        //building the stack
        for(int i=0;i<n;i++){
            if(taken[s[i]-'a']) continue;
            while( !st.empty() && (s[i]-'a')<(st.top()-'a') && last[st.top()-'a']>i ){
                taken[st.top()-'a']=0;
                st.pop();

            }

            if(taken[s[i]-'a']==false){
                taken[s[i]-'a']=true;
                st.push(s[i]);
            } 
                
        }

        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};