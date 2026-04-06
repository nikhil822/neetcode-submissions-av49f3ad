class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> ans = {0, 0};
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
                ans = {i, i + 1};
            }
        }
        for(int L = 2; L < n; L++) {
            for(int i = 0; i + L < n; i++) {
                int j = i + L;
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    ans = {i, j};
                } 
            }
        }
        return s.substr(ans[0], ans[1] - ans[0] + 1);
    }
};
