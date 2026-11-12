class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto i : strs) {
            int sz = i.size();
            ans = ans + to_string(sz) + "/:" + i;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            string temp = "";
            int j = i;
            while(j < n && s[j] != '/') {
                temp += s[j];
                j++;
            }
            int num = stoi(temp);
            j += 2;
            string res = "";
            int k = j;
            for(k = j; k < n && k < j + num; k++) {
                res += s[k];
            }
            i = k - 1;
            ans.push_back(res);
        }
        return ans;
    }
};
