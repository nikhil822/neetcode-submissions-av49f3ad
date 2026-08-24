class Solution {
public:
    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(i >= coins.size() || amount < 0)return 0;
        if(amount == 0)return 1;
        if(dp[i][amount] != -1)return dp[i][amount];
        int take = 0;
        if(coins[i] <= amount) {
            take = solve(i, coins, amount - coins[i], dp);
        }
        int notTake = solve(i + 1, coins, amount, dp);
        return dp[i][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(0, coins, amount, dp);
    }
};
