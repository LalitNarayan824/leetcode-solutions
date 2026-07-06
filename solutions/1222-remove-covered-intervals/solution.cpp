class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a , const vector<int> &b){
           if(a[0]==b[0]) return a[1]>b[1];
           return a[0]<b[0];
        });

        int n = intervals.size();
        vector<vector<int>> temp;

        temp.push_back(intervals[0]);

        vector<int> curr, prev;
        for(int i=1;i<n;i++){
            curr = intervals[i];
            prev = temp.back();

            if(prev[0]<=curr[0] && prev[1]>=curr[1]){
                


            }
            else{
                temp.push_back(curr);
            }
        }

        return temp.size();
        


                
    }
};



// [1,4] [2,8] [3,6]


// if we take the curr interval after sorting then 

// curr = [a,b]

// prev = [c,d]

// [c,d] [a,b]

// if(c<=a) and (d>=b) then the curr one will be eliminated