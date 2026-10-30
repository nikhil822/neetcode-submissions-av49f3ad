class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if(i >= nums.size() - 1) {
            return 0;
        }
        if(dp[i] != -1)return dp[i];
        int ans = INT_MAX;
        for(int j = 1; j <= nums[i]; j++) {
            int temp = solve(i + j, nums, dp);
            if(temp != INT_MAX)
            ans = min(ans, temp + 1);
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(0, nums, dp);
    }
};
