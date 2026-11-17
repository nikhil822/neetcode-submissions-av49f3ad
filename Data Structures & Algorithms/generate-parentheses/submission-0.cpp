class Solution {
public:
    vector<string> ans;
    void solve(int n, string& res, int open, int close) {
        if(open == close && open == n) {
            ans.push_back(res);
            return;
        }
        if(open < close || open > n || close > n){
            
            return;
        }
        res += "(";
        solve(n, res, open + 1, close);
        res.pop_back();
        res += ")";
        solve(n, res, open, close + 1);
        res.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string res = "";
        solve(n, res, 0, 0);
        return ans;
    }
};
