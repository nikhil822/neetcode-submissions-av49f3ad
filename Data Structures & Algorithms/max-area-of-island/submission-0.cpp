class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j] == 1)
            return 0;
        vis[i][j] = 1;
        return 1 + dfs(i + 1, j, grid, vis) + 
               dfs(i - 1, j, grid, vis) + 
               dfs(i, j + 1, grid, vis) + 
               dfs(i, j - 1, grid, vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    int cnt = dfs(i, j, grid, vis);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
