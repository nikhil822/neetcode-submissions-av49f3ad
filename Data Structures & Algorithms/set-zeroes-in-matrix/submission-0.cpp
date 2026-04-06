class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row = false, col = false;
        // check for 0 in first col with all the row
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                row = true;
            }
        }
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == 0) {
                col = true;
            }
        }

        // check for 0 in inner matrix and if found mark it's start row and col to 0
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // now mark 0 in each cell in which it's starting cell is 0
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(row) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if(col) {
            for(int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
