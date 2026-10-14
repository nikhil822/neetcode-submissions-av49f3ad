class Solution {
    vector<vector<int>> res;
public:
    void solve(int i, vector<int>& temp, vector<int>& nums, int target) {
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(i >= nums.size())return;
        
        for(int j = i; j < nums.size(); j++) {
            if(target < nums[j]){
                continue;
            } else {
                temp.push_back(nums[j]);
                solve(j, temp, nums, target - nums[j]);
            }
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(0, temp, nums, target);
        return res;
    }
};
