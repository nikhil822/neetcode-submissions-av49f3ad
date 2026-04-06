class Solution {
public:
int solve(int i, vector<int>& nums, int target, int res) {
        if(i >= nums.size()){
            if(res == target)return 1;
            return 0;
        }
        return solve(i + 1, nums, target, res + nums[i]) + solve(i + 1, nums, target, res - nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, target, 0);
    }
};
