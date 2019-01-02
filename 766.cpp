class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return true;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return true;
        }
        //the line equation is from row - col = m - 1 to row - col = -(n - 1)
        for (int d = m - 1; d >= -(n - 1); --d) {
            bool flag_first = false;
            int first_num = 0;
            for (int row = 0; row < m; ++row) {
                int col = row - d;
                if (col < 0 || col >= n) {
                    continue;
                }
                if (!flag_first) {
                    flag_first = true;
                    first_num = matrix[row][col];
                } else {
                    if (matrix[row][col] != first_num) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
