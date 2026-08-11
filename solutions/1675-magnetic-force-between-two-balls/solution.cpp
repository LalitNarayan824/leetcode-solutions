class Solution {
public:

    bool f(int dist , int m , vector<int> &pos){
        int tot =0;

        // we put one ball at pos[0]
        tot =1;
        int last = pos[0];
        for(int i=1;i<pos.size();i++){

            if(abs(pos[i]-last)>=dist){
                tot++;
                last = pos[i];
            }



        }

        return tot>=m;


    }


    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int range = *max_element(position.begin(), position.end()) - *min_element(position.begin(), position.end());
        // range is on min dist 
        int low = 1 , high = range;

        int ans = low;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(f(mid , m , position)){
                ans = mid ;
                low = mid+1;

            }
            else high = mid-1;
        }

        return ans;





    }
};