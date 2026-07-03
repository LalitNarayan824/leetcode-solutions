class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans =0 , n = s.size();


        int l=0 , r=0;
        vector<int> cnt(3, 0);
        // 0->a
        // 1->b
        // 2->c
        for(r=0;r<n;r++){
            if(s[r]=='a') cnt[0]++;
            else if(s[r]=='b') cnt[1]++;
            else cnt[2]++;

            bool all = true;

            for(int i=0;i<3;i++){
                if(cnt[i]==0){
                    all = false;
                    break;
                }
            }

            while(all){
                ans+=n-r;
                if(s[l]=='a') cnt[0]--;
                else if(s[l]=='b') cnt[1]--;
                else cnt[2]--;

                l++;
                for(int i=0;i<3;i++){
                    if(cnt[i]==0){
                    all = false;
                    break;
                    }
                }


            }

        }

        return ans;
    }
};