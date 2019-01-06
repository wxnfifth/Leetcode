class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        //find in each direction
        //per row
        int m = M.size();
        if (m == 0) {
            return 0;
        }
        int ans = 0;
        int n = M[0].size();
        for (int i = 0; i < m; ++i) {
            int last_pos = -1;
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    if (last_pos == -1) {
                        last_pos = j;
                    } 
                    ans = max(ans, j - last_pos + 1);
                } else {
                    last_pos = -1;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            int last_pos = -1;
            for (int i = 0; i < m; ++i) {
                if (M[i][j] == 1) {
                    if (last_pos == -1) {
                        last_pos = i;
                    }
                    ans = max(ans, i - last_pos + 1);
                } else {
                    last_pos = -1;
                }
            }
        }
        //diagonal, for left bottom, i - j = m - 1, for right top, i - j = 1 - n
        for (int k = m - 1; k >= 1 - n; --k) {
            //i[0,m)
            int last_pos = -1;
            for (int i = max(k, 0); i <= min(m - 1,n - 1 + k); ++i) {
                int j = i - k;
                if (M[i][j] == 1) {
                    if (last_pos == -1) {
                        last_pos = i;
                    }
                    ans = max(ans, i - last_pos + 1);
                } else {
                    last_pos = -1;
                }
            }
        }
        //anti-diagonal, for left top, i + j = 0, for right bottom, i + j = m + n - 2
        for (int k = 0; k <= m + n - 2; ++k) {
            int last_pos = -1;
            for (int i = max(k - n + 1, 0); i <= min(m - 1, k); ++i) {
                int j = k - i;
                if (M[i][j] == 1) {
                    if (last_pos == -1) {
                        last_pos = i;
                    }
                    ans = max(ans, i - last_pos + 1);
                } else {
                    last_pos = -1;
                }
            }
        }
        return ans;
    }
};
