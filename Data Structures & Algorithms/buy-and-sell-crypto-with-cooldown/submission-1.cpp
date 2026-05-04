class Solution {
public:
    int solve(int i, int flag, vector<int>& prices, vector<vector<int>>& dp) {
        if(i >= prices.size())return 0;
        if(dp[i][flag] != -1) {
            return dp[i][flag];
        }
        if(flag == 0) {
            return dp[i][flag] = max(-prices[i] + solve(i + 1, 1, prices, dp), solve(i + 1, 0, prices, dp));
        } else {
            return dp[i][flag] = max(prices[i] + solve(i + 2, 0, prices, dp), solve(i + 1, 1, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }
};
