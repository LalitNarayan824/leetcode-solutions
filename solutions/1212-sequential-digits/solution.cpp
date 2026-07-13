class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";

        vector<int> ans;

        // int size = 1;
        
        for(int size=1;size<=9;size++){
            for(int i=0;i<=9-size;i++){
                string temp = num.substr(i , size);
                int curr = stoi(temp);
                if(low<=curr && curr<=high) ans.push_back(curr);
            }
        }

        return ans;
    }
};