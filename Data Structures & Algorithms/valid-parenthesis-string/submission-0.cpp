class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openB, star;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                openB.push(i);
            } else if(s[i] == ')') {
                if(!openB.empty()){
                    openB.pop();
                }
                else if(!star.empty()){
                    star.pop();
                } else return false;
                
            } else star.push(i);
        }
        while(!openB.empty() && !star.empty()) {
            if(openB.top() > star.top())return false;
            openB.pop();
            star.pop();
        }
        
        return openB.empty();
    }
};
