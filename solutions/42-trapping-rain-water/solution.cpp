class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n, 0) , right(n, 0);
        int ans = 0 , water ;
        for(int i=1;i<n;i++){
            left[i] = max(height[i-1] , left[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            right[i] = max(height[i+1], right[i+1]);

            water = min(left[i], right[i]) - height[i];
            if(water>0) ans+=water;
        }

        return ans;

    }
};