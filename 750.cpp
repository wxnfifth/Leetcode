class Solution {
    
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        //enumerate 2 rows, count how many pair of 1 in each pair of row
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                int count = 0;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] == 1 && grid[j][k] == 1) {
                        count++;
                    }
                }
                ans += count * (count - 1) / 2;
            }
        }
        return ans;
    }
};
