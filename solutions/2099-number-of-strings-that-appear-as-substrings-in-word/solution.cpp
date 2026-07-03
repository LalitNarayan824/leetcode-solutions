class Solution {
public:

    bool find(string p , string s){

        int n = s.size();
        string temp;
        for(int i=0;i<n;i++){
            temp = "";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(temp==p) return 1;
            }
        }

        return 0;

    }


    int numOfStrings(vector<string>& patterns, string word) {
        int ans =0;

        for(auto &it : patterns){
            if(word.find(it)!=string::npos) ans++;
        }

        return ans;
    }
};