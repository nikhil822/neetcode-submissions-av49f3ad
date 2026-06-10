class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
       
        for(int i = 0; i <= amount; i++) {
            dp[coins.size()][i] = INT_MAX;
        }
        for(int i = coins.size() - 1; i >= 0; i--) {
            for(int a = 1; a <= amount; a++) {
                int take = INT_MAX;
                if(a >= coins[i]) {
                    take = dp[i][a - coins[i]];
                    if(take != INT_MAX) {
                        take++;
                    }
                }
                int notTake = dp[i + 1][a];
                dp[i][a] = min(take, notTake);
            }
        }
        return dp[0][amount] != INT_MAX ? dp[0][amount] : -1;
    }
};
