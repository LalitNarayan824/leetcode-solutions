class Solution {
public:
    int mySqrt(int x) {
        long long s =0 , e = x;

        while(s<=e){
            long long mid = s + (e-s)/2;
            long long t = mid*mid;
            if(t == x) return mid;

            if(t < x){
                s = mid+1;

            }
            else e = mid-1;
        }

        return (int)e;
    }
};