class Solution {
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int shortestDistance(vector<vector<int>>& grid) {
        //from building bfs to all position
        int m = grid.size();
        if (m == 0) {
            return -1;
        }
        int n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, 0));
        vector<vector<int>> count_can_reach(m, vector<int>(n , 0));
        int num_building = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }
                num_building++;
                vector<vector<int>> path_len(m, vector<int>(n , -1));
                queue<pair<int,int>> q;
                q.push(make_pair(i, j));
                path_len[i][j] = 0;
                while (!q.empty()) {
                    auto u = q.front();
                    q.pop();
                    if (grid[u.first][u.second] == 0) {
                        dis[u.first][u.second] += path_len[u.first][u.second];
                        count_can_reach[u.first][u.second]++;
                    }
                    for (int d = 0; d < 4; ++d) {
                        auto v = u;
                        v.first += dir[d][0];
                        v.second += dir[d][1];
                        if (v.first < 0 || v.second < 0 || v.first >= m || v.second >= n
                            || grid[v.first][v.second] != 0 || path_len[v.first][v.second] >= 0) {
                            continue;
                        }
                        q.push(v);
                        path_len[v.first][v.second] = path_len[u.first][u.second] + 1;
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (count_can_reach[i][j] == num_building && 
                    dis[i][j] < ans) {
                    ans = dis[i][j];
                }
            }
        }
        return ans == INT_MAX ? -1:ans;
    }
};
