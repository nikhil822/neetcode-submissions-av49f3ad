class MinStack {
public:
    stack<int> st, mn;
    MinStack() {
        // mn = INT_MAX;
    }
    
    void push(int val) {
        st.push(val);
        if(mn.empty()) {
            mn.push(val);
        } else if(mn.top() > val) {
            mn.push(val);
        } else {
            mn.push(mn.top());
        }
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
