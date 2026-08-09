class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(auto it : s){
            if(it==']'){
                
                string temp ="";

                while(!st.empty() && st.top()!='[' ){
                    temp += st.top();st.pop();
                }

                reverse(temp.begin(), temp.end());

                // pop the '['
                st.pop();

                int cnt = st.top()-'0';

                // get the number 
                string numbe ="";

                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    numbe+=st.top();st.pop();
                }

                int number =0 ;
                int pow = 1;

                for(auto it : numbe){
                    number += (int)(it-'0')*pow;
                    pow = pow*10;
                }



                

                // put back the chars now

                for(int i=1;i<=number;i++){
                    for(auto it : temp){
                        st.push(it);
                    }
                }



            }
            else{
                st.push(it);
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