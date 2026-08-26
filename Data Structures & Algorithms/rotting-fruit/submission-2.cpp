class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)q.push({i, j});
            }
        }
        int res = 0;
        int row[4] = {1, -1, 0, 0}, col[4] = {0, 0, -1, 1};
        while(!q.empty()) {
            int sz = q.size();
            res++;
            for(int i = 0; i < sz; i++) {
                auto ele = q.front();
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int nr = row[j] + ele.first, nc = col[j] + ele.second;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // cout << grid[i][j] << ' ';
                if(grid[i][j] == 1)return -1;
            }
        }
        if(res == 0)return 0;
        return res - 1;
    }
};
