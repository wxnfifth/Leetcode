class Solution {
    int getFather(vector<int>& father, int a) {
        while (father[a] != a) {
            int father_a = father[a];
            father[a] = father[father_a];
            a = father[a];
        }
        return a;
    }
    void unionSet(vector<int>& father, int a, int b) {
        if (father[a] == -1) {
            father[a] = a;
        }
        if (father[b] == -1) {
            father[b] = b;
        }
        father[getFather(father, a)] = getFather(father, b);
    }
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        //union set to solve
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        vector<int> father(m * n, -1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }
                if (father[i * n + j] == -1) {
                    father[i * n + j] = i * n + j;
                }
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dir[d][0];
                    int nj = j + dir[d][1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] =='0') {
                        continue;
                    }
                    unionSet(father, i * n + j , ni * n + nj);
                }
            }
        }        
        set<int> num_father;
        for (int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }
                num_father.insert(getFather(father, i * n + j));
            }
        }
        return num_father.size();
    }
};
