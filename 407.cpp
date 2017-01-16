//I think it's quite hard for me...


typedef pair<int,pair<int,int>> pr;

class cmp{
    public:
    bool operator()(const pr& a, const pr& b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        //use dijkstra algorithm
        // the sources are the boundary
        // everytime, get the cell with min height from the queue
        // update the volum with max height - current height
        priority_queue<pr, vector<pr>, cmp> que; // first is height, second is location
        //priority_queue<pr> que;
        //set sources
        int m = heightMap.size();
        if (m == 0) {
            return 0;
        }
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            que.push(make_pair(heightMap[i][0], make_pair(i,0)));
            visited[i][0] = true;
            que.push(make_pair(heightMap[i][n - 1], make_pair(i, n - 1)));
            visited[i][n-1] = true;
        }
        for (int j = 0; j < n; ++j) {
            que.push(make_pair(heightMap[0][j], make_pair(0,j)));
            visited[0][j] = true;
            que.push(make_pair(heightMap[m-1][j],make_pair(m-1,j)));
            visited[m-1][j] = true;
        }
        
        int max_height = INT_MIN;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int ans = 0;
        while (!que.empty()) {
            auto u = que.top();
            que.pop();
            max_height = max(max_height, u.first);
            auto u_pos = u.second;
            for (int d = 0; d < 4; ++d) {
                auto v_pos = make_pair(u_pos.first + dir[d].first, u_pos.second + dir[d].second);
                if (v_pos.first < 0 || v_pos.first >= m || v_pos.second < 0 || v_pos.second >= n ||
                    visited[v_pos.first][v_pos.second]) {
                    continue;
                }
                if (heightMap[v_pos.first][v_pos.second] < max_height) {
                    ans += max_height - heightMap[v_pos.first][v_pos.second];
                }
                visited[v_pos.first][v_pos.second] = true;
                que.push(make_pair(heightMap[v_pos.first][v_pos.second], v_pos));
            }
        }
     
        return ans;
    }
};