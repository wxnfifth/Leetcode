class Solution {
    int dir[8][2] = {{1,0}, {-1,0}, {0, 1}, {0, -1}, {1, -1}, {1,1}, {-1,1}, {-1,-1}};

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> nums(board);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dir[d][0];
                    int nj = j + dir[d][1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                        continue;
                    }
                    if (board[ni][nj] == 'M') {
                        count++;
                    }
                }
                if (board[i][j] != 'M') {
                    nums[i][j] = count + '0';
                }
            }
        }
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        } else if (board[click[0]][click[1]] == 'E') {
            //bfs to reveal board
            queue<vector<int>> q;
            if (nums[click[0]][click[1]] >= '1' && nums[click[0]][click[1]] <= '9') {
                board[click[0]][click[1]] = nums[click[0]][click[1]];
            } else {
                board[click[0]][click[1]] = 'B';
                q.push(click);
            }
            while (!q.empty()) {
                vector<int> u = q.front();
                q.pop();
                if (board[u[0]][u[1]] == 'B') {
                    for (int d = 0; d < 8; ++d) {
                        vector<int> adj = u;
                        adj[0] += dir[d][0];
                        adj[1] += dir[d][1];
                        if (adj[0] < 0 || adj[0] >= m || adj[1] < 0 || adj[1] >= n) {
                            continue;
                        }
                        if (nums[adj[0]][adj[1]] >= '1' && nums[adj[0]][adj[1]] <= '9') {
                            board[adj[0]][adj[1]] = nums[adj[0]][adj[1]];
                        } else if (board[adj[0]][adj[1]] == 'E') {
                            board[adj[0]][adj[1]] = 'B';
                            q.push(adj);
                        }
                    }
                }
            }
            return board;
        }
    }
};
