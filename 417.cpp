class Solution {
    
private:
    vector<pair<int,int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
    
    void bfs(const vector<vector<int>>& matrix, const vector<pair<int,int>>& initial, int m, int n, vector<vector<int>>& ans_matrix) {
        vector<vector<bool>> tmp_matrix(m, vector<bool>(n, false));
        queue<pair<int,int>> que;
        for (auto i:initial) {
            que.push(i);
            tmp_matrix[i.first][i.second] = true;
        }
        
        while (!que.empty()) {
            auto u = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i) {
                auto v = make_pair(u.first + dir[i].first, u.second + dir[i].second);
                if (v.first < 0 || v.first >= m || v.second < 0 || v.second >= n) {
                    continue;
                }
                if (matrix[u.first][u.second] <= matrix[v.first][v.second] && tmp_matrix[v.first][v.second] == false) {
                    que.push(v);
                    tmp_matrix[v.first][v.second] = true;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (tmp_matrix[i][j]) {
                    ans_matrix[i][j]++;
                }
            }
        }

    }
    
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return vector<pair<int,int>>();
        }
        int n = matrix[0].size();
        vector<vector<int>> ans_matrix(m, vector<int>(n,0));
        vector<pair<int,int>> pacific_pos;
        for (int i = 0; i < n; ++i) {
            pacific_pos.push_back(make_pair(0,i));
        }
        for (int i = 0; i < m; ++i) {
            pacific_pos.push_back(make_pair(i,0));
        }
        bfs(matrix, pacific_pos, m, n, ans_matrix);
        
        vector<pair<int,int>> atlantic_pos;
        for (int i = 0; i < n; ++i) {
            atlantic_pos.push_back(make_pair(m - 1, i));
        }
        for (int i = 0; i < m; ++i) {
            atlantic_pos.push_back(make_pair(i, n - 1));
        }
        bfs(matrix, atlantic_pos, m, n, ans_matrix);
        
        
        vector<pair<int,int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ans_matrix[i][j] == 2) {
                    ans.push_back(make_pair(i,j));
                }
            }
        }
        return ans;
    }
};