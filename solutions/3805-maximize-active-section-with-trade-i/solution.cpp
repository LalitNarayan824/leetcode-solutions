class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string temp = "";
        int n = s.size();

        char prev = s[0];  // init
        int curr = 0; // count of current character 
        int tot = 0; //  total number of ones initially
        vector<int> cnt;
        for(char &it : s){
            if(it == prev){
                curr++;
            }
            else{
                temp += prev;
                // temp += /(curr + '0');
                cnt.push_back(curr);
                prev = it;
                curr = 1; 
            }

            if(it=='1') tot++;
        }

        temp += prev;
        // temp += (curr + '0');
        cnt.push_back(curr);

        cout<<temp;

        // our temp is like   char num char num char num . . . . 

        // ultimaltely after a trade some 0 becomes 1 and original number of 1 increases 

        // so in patch of 0...1...0... , these number of zeroes gets converted to one , so we need to
        // maximize such patch where the number of ones is max

        int index =0;
        int m = temp.size();
        int maxi = 0;

            
        while(index<m){
            if(temp[index]=='1'){
                // we check if this is surrounded by zeros
                if( (index-1)>=0 && temp[index-1]=='0' && (index+1)<m && temp[index+1]=='0' ){
                    maxi = max(maxi , (cnt[index-1]) + (cnt[index+1]));
                }

            }
            index+=1;
            
        }

        tot += maxi;

        return tot;
    }
};

// this one can only handle number of ones or zeroes less than 10 ie two digits