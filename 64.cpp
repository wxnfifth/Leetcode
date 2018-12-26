class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n, INT_MAX));
        sum[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    sum[i][j] = min(sum[i][j], sum[i - 1][j] + grid[i][j]);
                }
                if (j > 0) {
                    sum[i][j] = min(sum[i][j], sum[i][j - 1] + grid[i][j]);
                }
            }
        }
        return sum[m - 1][n - 1];
    }
};
