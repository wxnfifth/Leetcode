class Solution {
    int max_len;
    
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(const vector<vector<int>>& matrix, vector<vector<int>>& dp, int si, int sj, int m, int n) {
        if (dp[si][sj] != 0) {
            return;
        }
        dp[si][sj] = 1;
        for (int d = 0; d < 4; ++d) {
            int ni = si + dir[d][0];
            int nj = sj + dir[d][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                continue;
            }
            if (matrix[ni][nj] > matrix[si][sj]) {
                dfs(matrix, dp, ni, nj, m, n);
                dp[si][sj] = max(dp[si][sj], dp[ni][nj] + 1);
            }
        }
        max_len = max(max_len, dp[si][sj]);
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        max_len = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(matrix, dp, i, j, m, n);
            }
        }
        
        return max_len;
        
    }
};