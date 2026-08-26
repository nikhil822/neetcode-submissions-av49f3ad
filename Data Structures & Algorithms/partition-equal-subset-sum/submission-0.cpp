class Solution {
public:
    bool solve(int i, vector<int>& nums, int sum, vector<vector<int>>& dp) {
        if(i >= nums.size())return false;
        if(sum == 0)return true;
        if(dp[i][sum] != -1)return dp[i][sum];
        bool take = false;
        if(nums[i] <= sum) {
            take = solve(i + 1, nums, sum - nums[i], dp);
        }
        return dp[i][sum] = take || solve(i + 1, nums, sum, dp) ? 1 : 0;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum & 1)return false;
        sum /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
        return solve(0, nums, sum, dp);
    }
};
