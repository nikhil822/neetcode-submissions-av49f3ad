class Solution {
public:
    vector<vector<string>> ans;
    bool isPalind(string &st) {
        int i = 0, j = st.size() - 1;
        while(i <= j) {
            if(st[i] != st[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i, vector<string>& temp, string& s) {
        if(i == s.size()) {
            ans.push_back(temp);
            return;
        }
        for(int j = i; j < s.size(); j++) {
            string st = s.substr(i, j - i + 1);
            if(isPalind(st)) {
                temp.push_back(st);
                solve(j + 1, temp, s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0, temp, s);
        return ans;
    }
};
