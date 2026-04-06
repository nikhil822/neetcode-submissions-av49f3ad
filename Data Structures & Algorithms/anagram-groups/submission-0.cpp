class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> res;
        for(auto i : mp) {
            vector<string> v;
            for(auto j : i.second) {
                v.push_back(strs[j]);
            }
            res.push_back(v);
        }
        return res;
    }
};
