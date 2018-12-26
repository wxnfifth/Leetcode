class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int i = 0;
        int j = -1;
        int count = 1;
        while (count <= n * n) {
            while (j + 1 < n && m[i][j + 1] == 0 && count <= n * n) {
                j++;
                m[i][j] = count;
                count++;
            }
            while (i + 1 < n && m[i + 1][j] == 0 && count <= n * n) {
                i++;
                m[i][j] = count;
                count++;
            }
            while (j - 1 >= 0 && m[i][j - 1] == 0 && count <= n * n) {
                j--;
                m[i][j] = count;
                count++;
            }
            while (i - 1 >= 0 && m[i - 1][j] == 0 && count <= n * n) {
                i--;
                m[i][j] = count;
                count++;
            }
        }
        return m;
    }
};
