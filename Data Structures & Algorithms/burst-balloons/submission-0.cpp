class Solution {
public:
    int mcm(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        for(int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1] + mcm(i, k - 1, nums, dp) + mcm(k + 1, j, nums, dp);
            ans = max(ans, coins);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(305, vector<int>(305, -1));
        return mcm(1, nums.size() - 2, nums, dp);
    }
};
