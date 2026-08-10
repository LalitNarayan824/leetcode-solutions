class Solution {
public:
    bool isPerfectSquare(int num) {
        long long s =0 , e = num;

        while(s<=e){
            long long mid = s + (e-s)/2;
            long long t = mid*mid;

            if(t==num){
                return true;
            }

            if(t < num){
                s =mid+1;
            }
            else{
                e =mid-1;
            }
        }

        return false;
    }
};