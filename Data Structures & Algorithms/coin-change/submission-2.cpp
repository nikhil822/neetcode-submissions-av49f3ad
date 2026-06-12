class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;       
        
        for(int i = coins.size() - 1; i >= 0; i--) {
            for(int a = 1; a <= amount; a++) {
                int take = INT_MAX;
                if(a >= coins[i]) {
                    take = dp[a - coins[i]];
                    if(take != INT_MAX) {
                        take++;
                    }
                }
                int notTake = dp[a];
                dp[a] = min(take, notTake);
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
