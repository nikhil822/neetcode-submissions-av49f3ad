class Solution {
    vector<vector<string>> ans;
    vector<string> res;
public:
    bool isValid(int row, int col) {
        for(int c = 0; c < res.size(); c++) {
            if(res[row][c] == 'Q')return false;
        }
        for(int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            if(res[r][c] == 'Q')return false;
        }
        for(int r = row, c = col; r < res.size() && c >= 0; r++, c--) {
            if(res[r][c] == 'Q')return false;
        }
        return true;
    }

    void solve(int col) {
        if(col == res.size()){
            ans.push_back(res);
            return;
        }
        for(int i = 0; i < res.size(); i++) {
            if(isValid(i, col)) {
                res[i][col] = 'Q';
                solve(col + 1);
                res[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        res.resize(n, string(n, '.'));
        solve(0);
        return ans;
    }
};
