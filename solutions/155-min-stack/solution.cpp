class MinStack {
public:

    stack<int> st;
    stack<int> mini;

    MinStack() {
        
    }
    
    void push(int value) {
       if(st.empty()){
            st.push(value);
            mini.push(value);
       } 
       else{
            st.push(value);
            mini.push(min(value , mini.top()));
       }
    }
    
    void pop() {
       st.pop();
       mini.pop();


    }


    
    int top() {
        return st.top();    
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */