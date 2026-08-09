class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();

        stack<char> st;
        char last ;
        int count =0;
        for(int i=0;i<n;i++){

            // empty condition
            if(st.empty()){
                st.push(s[i]);
                last = s[i];
                count = 1;
                continue;
            }

            st.push(s[i]);
            if(last==s[i]){
                count++;
            }
            else{
                last = s[i];count=1;
            }

            if(count==k){
                for(int i=1;i<=k;i++) st.pop();

                if(st.empty()){
                    continue;
                }

                last=st.top();
                count=0;

                stack<char> temp;
                while( !st.empty() && st.top()==last){
                    temp.push(st.top());
                    st.pop();
                    count++;
                }

                while(!temp.empty()){
                    st.push(temp.top());
                    temp.pop();
                }


            }


        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

