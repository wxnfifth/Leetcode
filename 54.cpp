class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int cnt = 1;
        int m = matrix.size();
        if (m == 0) {
            return vector<int>();
        }
        int n = matrix[0].size();
        vector<int> ans;
        int i = 0;
        int j = -1;
        int len_m = m - 1;
        int len_n = n;
        while (cnt <= m * n) {
            for (int k = 0; k < len_n && cnt <= m * n; ++k) {
                j++;
                cnt++;
                ans.push_back(matrix[i][j]);
            }
            len_n--;
            for (int k = 0; k < len_m && cnt <= m * n; ++k) {
                i++;
                cnt++;
                ans.push_back(matrix[i][j]);
            }
            len_m--;
            for (int k = 0; k < len_n && cnt <= m * n; ++k) {
                j--;
                cnt++;
                ans.push_back(matrix[i][j]);
            }
            len_n--;
            for (int k = 0; k < len_m && cnt <= m * n; ++k) {
                i--;
                cnt++;
                ans.push_back(matrix[i][j]);
            }
            len_m--;
        }
        return ans;
    }
};
