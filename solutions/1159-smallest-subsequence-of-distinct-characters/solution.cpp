class Solution {
public:


    // TC -> O(n) as its linear
    // SC -> O(1) lastIndex and taken of size 26 and res stack at max = 26

    string smallestSubsequence(string s) {
        // lastIndex and taken

        vector<int> lastIndex(26 , -1);
        vector<bool> taken(26 , false);
        int n = s.size();
        for(int i=0;i<n;i++){
            lastIndex[s[i]-'a']=i;
        }

        string res="";
        int index =0;
        while(true){
            if(index>=n) break;

            // stack empty condition
            if(res.size()==0){
                res.push_back(s[index]);
                taken[s[index]-'a']= true;
                index++;
                continue;
            }

            // already present in stack condition
            if(taken[s[index]-'a']){
                index++;
                continue;
            }

            // at this point the char is not present in the stack and stack is not empty

            // if lexographically smaller than top of stack
            if(res.back() < s[index]){
                res.push_back(s[index]);
                taken[s[index]-'a'] = true;
                index++;

            }
            else{
            // if lexographically greater than top of stack
                if(lastIndex[res.back()-'a']> index){
                    taken[res.back()-'a']=false;
                    res.pop_back();
                }
                else{
                    res.push_back(s[index]);
                    taken[s[index]-'a'] = true;
                    index++;
                }
            }






        }

        return res;
    }
};