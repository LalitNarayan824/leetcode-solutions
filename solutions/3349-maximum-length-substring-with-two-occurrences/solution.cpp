class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0 , n = s.size() ,  r , ans =0;

        unordered_map<char , int> f;




        for(r =0;r<n;r++){
            char c = s[r];
            if(f.find(c)==f.end()){
                f[c]=1;
            }
            else{
                if(f[c]<2){
                    f[c]++;
                }
                else{
                    // right now the count of c is 2 , without adding the current char
                    while(s[l]!=c){
                        f[s[l]]--;
                        if(f[s[l]]==0){
                            f.erase(s[l]);
                        }
                        l++;
                    }

                    l++;

                }


            }

            ans = max(ans , r - l+1);





        }

        return ans;
    }
};