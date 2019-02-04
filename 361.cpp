class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        //for each position, save e can be killed on a row and e can be killed on a column
        //then find result
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        vector<vector<int>> erow(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            int last = 0;
            int j = 0;
            while (j <= n) {
                if (j == n || grid[i][j] == 'W') {
                    for (int k = last; k < j; ++k) {
                        erow[i][k] = cnt;
                    }
                    cnt = 0;
                    last = j + 1;
                } else if (grid[i][j] == 'E') {
                    cnt++;
                } 
                j++;
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            int last = 0;
            int i = 0;
            while (i <= m) {
                if (i == m || grid[i][j] == 'W') {
                    for (int k = last; k < i; ++k) {
                        if (grid[k][j] == '0') {
                            ans = max(ans, erow[k][j] + cnt);
                        }
                    }
                    cnt = 0;
                    last = i + 1;
                } else if(grid[i][j] == 'E') {
                    cnt++;
                } 
                i++;
            }
        }
        return ans;
    }
};
