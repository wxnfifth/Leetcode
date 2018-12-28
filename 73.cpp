class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return;
        }
        bool flag_first_row_0 = false;
        bool flag_first_col_0 = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                flag_first_col_0 = true;
                break;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                flag_first_row_0 = true;
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_first_col_0) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (flag_first_row_0) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j ] = 0;
            }
        }
        
        
        
    }
};
