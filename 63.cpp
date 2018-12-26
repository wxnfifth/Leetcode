class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        vector<vector<int>> num(m, vector<int>(n, 0));
        if (grid[0][0] == 1) {
            return 0;
        }
        num[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    continue;
                }
                if (i > 0) {
                    num[i][j] += num[i - 1][j];
                }
                if (j >0) {
                    num[i][j] += num[i][j - 1];
                }
            }
        }
        return num[m - 1][n - 1];
    }
};
