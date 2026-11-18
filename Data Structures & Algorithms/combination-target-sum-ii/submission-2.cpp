class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> s;
    void solve(int i, vector<int>& candidates, int target, vector<int>& temp) {
        if(target == 0) {
            s.insert(temp);
            return;
        }
        if(target < 0 || i >= candidates.size())return;
        for(int j = i; j < candidates.size(); j++) {
            if(target - candidates[j] < 0)break;
            if(j > i && candidates[j] == candidates[j - 1])continue;
            temp.push_back(candidates[j]);
            solve(j + 1, candidates, target - candidates[j], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(0, candidates, target, temp);
        for(auto i : s) {
            res.push_back(i);
        }
        return res;
    }
};
