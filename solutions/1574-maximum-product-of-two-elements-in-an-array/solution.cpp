class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m =-1 , sm =-1;

        for(auto & it : nums){
            if(m==-1 && sm==-1){
                m = it;
            }
            else{
                if(it>=m){
                    sm = m;
                    m = it;

                }
                else if( it>sm ){
                    sm = it;
                }
            }
        }

        return (m-1)*(sm-1);
    }
};