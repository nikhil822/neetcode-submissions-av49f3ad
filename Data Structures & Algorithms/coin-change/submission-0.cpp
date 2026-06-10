class Solution {
public:
    int solve(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(amount == 0){
            return 0;
        } 
        if(idx == coins.size())return INT_MAX;
        if(dp[idx][amount] != -1)return dp[idx][amount];
        int take = INT_MAX;
        if(amount >= coins[idx]){
            take = solve(idx, coins, amount - coins[idx], dp);
            if(take != INT_MAX)
                take += 1;
        }
        int notTake = solve(idx + 1, coins, amount, dp);
        return dp[idx][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = solve(0, coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
