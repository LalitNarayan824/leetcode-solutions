class Solution {
public:
    int smallestNumber(int n, int t) {
        int m = n;
        while(true){
            int k = m;
            int prod = 1;
            while(k){
                prod = prod * (k%10);
                k = k/10;
            }

            if(prod % t == 0) return m;
            m++;
        }

        return -1;
    }
};