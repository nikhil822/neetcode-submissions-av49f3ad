class Solution {
    vector<vector<int>> vis;
    int m, n;
public:
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string word) {
        if(idx >= word.size())return true;
        if(i >= m || j >= n || i < 0 || j < 0 || vis[i][j] == 1)return false;
        if(word[idx] != board[i][j])return false;
        vis[i][j] = 1;
        bool flag = dfs(i + 1, j, idx + 1, board, word) ||
                dfs(i - 1, j, idx + 1, board, word) || 
                dfs(i, j + 1, idx + 1, board, word) || 
                dfs(i, j - 1, idx + 1, board, word);
        vis[i][j] = 0;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vis.resize(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};
