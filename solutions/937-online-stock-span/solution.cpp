class StockSpanner {
public:

    stack<int> t;
    stack<int> st;
    int day = 0;
    StockSpanner() {
        
    }
    // st 100 85  
    // t  0 6
    // day 7
    int next(int price) {
        if(st.empty()){
            st.push(price);
            t.push(day++);
            return 1;
        }

        if(price < st.top()){
            st.push(price);
            
            t.push(day++);
            return 1;
        }

        while(!st.empty() && price >= st.top()){
            st.pop();
            t.pop();
        }
        int ans ;
        if(st.empty()){
            ans = day+1;

        }
        else{
            ans = day - t.top();
        }

        st.push(price);
        t.push(day++);

        return ans;


    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

//  100 , 80 , 60 , 70 , 60 , 75 , 85
//  -1  , 100, 80 , 80 , 70 , 80 , 100