class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        if(n==1) return 1;
        
        int odd = 0 , even =0;


        int num=1;
        for(int i=1;i<=n;i++){
            odd+=num;
            num+=2;
        }
        num=2;
        for(int i=1;i<=n;i++){
            even+=num;
            num+=2;
        }

        while(odd!=0){
            int temp = odd;
            odd= even%odd;
            even = temp;
        }

        return even;
    }
};