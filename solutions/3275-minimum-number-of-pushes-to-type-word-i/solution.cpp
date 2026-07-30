class Solution {
public:
    int minimumPushes(string word) {
        vector<int> keypad(26, -1);


        int push=1;
        int cnt =0;
        int ans =0;
        // build the keypad
        for(auto &c : word){
            if(keypad[c-'a']==-1){
                keypad[c-'a'] = push;
                cnt++;
                ans+=push;
                if(cnt==8){
                    cnt=0;
                    push++;
                }
            }
            else ans += keypad[c-'a'];

        }

        return ans;


    }
};