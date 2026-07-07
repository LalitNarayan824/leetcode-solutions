class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0 ;
        long long num = 0;

        while(n){
            if(n%10!=0) num = num*10 + n%10;
            sum+= n%10;
            n = n/10;
        }

        long long x = 0;
        while(num){
            x = x*10 + num%10;
            num= num/10;
        }

        return x*sum;


    }
};