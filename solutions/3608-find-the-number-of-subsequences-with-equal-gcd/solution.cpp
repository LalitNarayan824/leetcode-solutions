class Solution {
public:


    const int INF = 1e9 + 7;
    vector<int> temp;
    int n;

    int f(int index , int seq1 , int seq2, vector<vector<vector<int>>> &dp){

        //base case
        if(index==n){
            if(seq1==seq2 && seq1!=0 && seq2!=0) return 1;
            else return 0;
        }

        if(dp[index][seq1][seq2]!=-1) return dp[index][seq1][seq2];


        // other
        int ans =0;
        // temp[index] added to seq1
        ans = (ans+ f(index+1 , gcd(temp[index], seq1) , seq2, dp ))%INF;
        // temp[index] added to seq2
        ans = (ans + f(index+1 , seq1 , gcd(temp[index], seq2) , dp ))%INF;
        // temp[index] goes to none
        ans = (ans + f(index+1 , seq1 , seq2 , dp )) %INF;

        return dp[index][seq1][seq2] = ans %INF;




    }


    int subsequencePairCount(vector<int>& nums) {
        temp = nums;
        n = nums.size();
        int maxi = -1;
        for(auto &it : nums) maxi = max(maxi , it);

        vector<vector<vector<int>>> dp( n , vector<vector<int>>(maxi+1 , vector<int>(maxi +1 , -1)));

        int seq1=0 , seq2=0;
        return f(0 , seq1 , seq2 , dp);    
    }
};