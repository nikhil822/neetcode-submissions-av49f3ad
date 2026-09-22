class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({grid[0][0], 0, 0});
        vector<vector<int>> vis(n, vector<int>(n, -1));
        vis[0][0] = 1;
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto temp = q.top();
            cout << temp[0] << ' ';
            q.pop();
            res = max(res, temp[0]);
            if(temp[1] == n - 1 && temp[2] == n - 1) return res;
            for(int i = 0; i < 4; i++) {
                int nr = row[i] + temp[1], nc = col[i] + temp[2];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == -1) {
                    vis[nr][nc] = 1;
                    q.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return 0;
    }
};
