class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = lights.size() , k = arrivalTime.size();

        for(int i=0;i<k;i++){
            arrivalTime[i] = arrivalTime[i]%period;
        }


        // sort(arrivalTime.begin(), arrivalTime.end());
        int maxL = INT_MIN;
        for(auto it : lights) maxL = max(maxL , it);

        int maxP=0;

        for(int i=0;i<k;i++){
            if(arrivalTime[i]<maxL){
                // no penaly
            }
            else{
                maxP = max(maxP , period - arrivalTime[i]);             
            }
        }

        return maxP;
        
    }
};