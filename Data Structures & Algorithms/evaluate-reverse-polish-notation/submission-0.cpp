class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto i : tokens) {
            if(i == "+" || i == "-" || i == "*" || i == "/") {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                int res;
                if(i == "+")res = n1 + n2;
                else if(i == "-")res = n1 - n2;
                else if(i == "*")res = n1 * n2;
                else if(i == "/")res = n1 / n2;
                st.push(res);
            } else {
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};
