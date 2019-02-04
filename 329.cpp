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


//now solution
class Solution {
    vector<vector<int>> path_len;
    int m = 0;
    int n = 0;
    int dir[4][2] = {{-1, 0}, {1,0},{0,1},{0,-1}};
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (path_len[i][j] > 1) {
            return path_len[i][j];
        }
        int ans = 1;
        for (int d = 0; d < 4; ++d) {
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || 
                matrix[i][j] >= matrix[ni][nj]) {
                continue;
            }
            ans = max(ans, dfs(ni, nj, matrix) + 1);
        }
        path_len[i][j] = ans;
        return ans;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //use dfs to find longest increasing for each position
        //memory each position
        m = matrix.size();
        if (m == 0) {
            return 0;
        }
        n = matrix[0].size();
        path_len = vector<vector<int>>(m, vector<int>(n, 1));
        int ans = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
};
