class Solution {
public:
    string smallestPalindrome(string s) {
        // take the characters and make the smallest palindrome possible

        // observation
        // since we took it from a palindrome , all char will be even except one or zero

        vector<int> f(26  , 0);

        for(auto &c : s){
            f[c-'a']++;
        }

        // let palindrome = str1 + str1.rev()

        string s1 = "";
        char oddChar ;
        int oddCount = 0 ;
        for( int i =0 ; i<26 ; i++ ){
            if(f[i]&1){
                oddChar = (char)('a' + i);
                oddCount = 1;
                // continue;
            }


            if(f[i]>0) s1 += string( f[i]/2  , (char)(i+'a'));
            // str2 += string((i+'a') , f[i]/2);
        }

        string ans = s1;

        if(oddCount){
            ans += string(oddCount , oddChar);
        } 

        reverse(s1.begin() , s1.end());

        ans += s1;

        return ans;



    }
};