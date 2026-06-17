class MinStack {
public:
    stack<long> st;
    long mn;
    MinStack() {
        // mn = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(0);
            mn = val;
        } else {
            st.push(val - mn);
            if(val < mn)mn = val;
        }
    }
    
    void pop() {
        if(st.empty())return;
        if(st.top() >= 0)
            st.pop();
        else {
            mn -= st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top() > 0 ? st.top() + mn : mn;
    }
    
    int getMin() {
        return mn;
    }
};
