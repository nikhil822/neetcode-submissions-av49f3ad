class Solution {
public:
    vector<string> res;
    unordered_map<char, string> m;
    void solve(int i, string digits, string& temp) {
        if(i >= digits.size()){
            res.push_back(temp);
            return;
        }
        string toBeIterate = m[digits[i]];
        for(int j = 0; j < toBeIterate.size(); j++) {
            temp += toBeIterate[j];
            solve(i + 1, digits, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")return res;
        m['2'] = "abc";m['3'] = "def";m['4'] = "ghi";m['5'] = "jkl";
        m['6'] = "mno";m['7'] = "pqrs";m['8'] = "tuv";m['9'] = "wxyz";
        string temp = "";
        solve(0, digits, temp);
        return res;
    }
};
