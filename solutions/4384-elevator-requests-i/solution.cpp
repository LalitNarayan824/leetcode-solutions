class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int prev = 0;
        int ans =0;

        for(auto it : requests){
            ans += abs(it-prev);

            prev= it;
            
        }

        return ans;
    }
};