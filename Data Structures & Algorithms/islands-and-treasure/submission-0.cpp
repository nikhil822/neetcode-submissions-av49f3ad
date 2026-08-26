class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    pq.push({0, i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int row[4] = {1, -1, 0, 0}, col[4] = {0, 0, 1, -1};
        while(!pq.empty()) {
            auto ele = pq.top();
            int di = ele[0], r = ele[1], c = ele[2];
            pq.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + row[i], nc = c + col[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != -1 && vis[nr][nc] == 0) {
                    grid[nr][nc] = di + 1;
                    vis[nr][nc] = 1;
                    pq.push({di + 1, nr, nc});
                }
            }
        }
    }
};
