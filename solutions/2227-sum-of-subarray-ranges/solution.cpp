class Solution {
public:

    const int MOD = 1e9+7;

    long long sumSubarrayMins(vector<int>& arr) {
        // stand on a element , and figure out next smallest and prev smallest element

        int n = arr.size();

        vector<int> nse(n) , pse(n);
        stack<int> st;

        //building nse
        for(int i=n-1;i>=0;i--){
            int el = arr[i];
            if(st.empty()){
                st.push(i);
                nse[i] = n;
                continue;
            }

            if( el > arr[st.top()]){
                nse[i] = st.top();
                st.push(i);
                continue;
            }

            while( !st.empty() && el < arr[st.top()] ){
                st.pop();
            }

            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()) st.pop();
        //building pse
        for(int i=0;i<n;i++){
            int el = arr[i];
            if(st.empty()){
                st.push(i);
                pse[i] = -1;
                continue;
            }

            if( el > arr[st.top()]){
                pse[i] = st.top();
                st.push(i);
                continue;
            }

            while( !st.empty() && el <= arr[st.top()] ){
                st.pop();
            }

            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }

            st.push(i);
        }

        // now we have nse and pse

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pse[i];      // choices on left
            long long right = nse[i] - i;     // choices on right

            ans = (ans +  arr[i] * left * right);
        }

        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        // stand on a element , and figure out next smallest and prev smallest element

        int n = arr.size();

        vector<int> nse(n) , pse(n);
        stack<int> st;

        //building nse
        for(int i=n-1;i>=0;i--){
            int el = arr[i];
            if(st.empty()){
                st.push(i);
                nse[i] = n;
                continue;
            }

            if( el < arr[st.top()]){
                nse[i] = st.top();
                st.push(i);
                continue;
            }

            while( !st.empty() && el > arr[st.top()] ){
                st.pop();
            }

            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()) st.pop();
        //building pse
        for(int i=0;i<n;i++){
            int el = arr[i];
            if(st.empty()){
                st.push(i);
                pse[i] = -1;
                continue;
            }

            if( el < arr[st.top()]){
                pse[i] = st.top();
                st.push(i);
                continue;
            }

            while( !st.empty() && el >= arr[st.top()] ){
                st.pop();
            }

            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }

            st.push(i);
        }

        // now we have nse and pse

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pse[i];      // choices on left
            long long right = nse[i] - i;     // choices on right

            ans = (ans +  arr[i] * left * right);
        }

        return ans;
    }

    


    long long subArrayRanges(vector<int>& nums) {
        // ANS = sum of subarray maximum - sum of subarray minimum

        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};