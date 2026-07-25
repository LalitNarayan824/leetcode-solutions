class Solution {
public:
    int maxProduct(int n) {
        int one = -1 , two =-1;

        while(n){
            int num = n %10;
            
            // one =-1 && two= -1
            // one = num && two = -1
            // one = num && two = num
            if(one==-1 && two==-1){
                one = num;
            }
            else{
                if(num > one){
                    two = one;
                    one = num;
                }
                else if(num==one){
                    two = num;
                }
                else if(num < one && num > two){
                    two = num;
                }
            }
            
            n = n/10;
        }

        return one * two;
    }

};