class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> right(n) , left(n);


        stack<int> st;

        for(int i=n-1;i>=0;i--){
            int ele = heights[i];
            while(!st.empty() && ele <= heights[st.top()]){
                st.pop();
            }

            if(st.empty()){
                right[i] = n;
            }
            else{
                right[i] = st.top();
            }

            st.push(i);

        }

        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++){
            int ele = heights[i];
            while(!st.empty() && ele <= heights[st.top()]){
                st.pop();
            }

            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }

            st.push(i);

        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans , heights[i]*(right[i]-left[i]-1));
        }

        return ans;

    }
};