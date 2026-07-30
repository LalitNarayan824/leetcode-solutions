class Solution {
public:

    // TC = O(n) + K , n = size of word
    // SC = O(k) k = constant

    int minimumPushes(string word) {
        vector<int> sfm(26, 0);


        int push=1;
        int cnt =0;
        int ans =0;
        // we need to sort it by freq first
        
       
        // O(n)
        for(auto &c : word){
            sfm[c-'a']++;
        }

        
        
        //O(klogk) k=26 -> constant
        sort(sfm.begin(), sfm.end(), [](int a ,int b){
            return a>b;
        });

        // keypad = vector<int>(26 , -1);

        // build the keypad
        // O(26)
        for(auto temp : sfm){
            
            
                // cout<<(char(i+'a'))<<" ";
                cnt++;
                ans+=push*temp;
                if(cnt==8){
                    cnt=0;
                    push++;
                }
            

        }

        return ans;


    }
};