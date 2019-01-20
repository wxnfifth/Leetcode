class Solution {
public:
    vector<int> findOrder(int n, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> in_degree(n, 0);
        for (auto p:prerequisites) {
            graph[p.second].push_back(p.first);
            in_degree[p.first]++;
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v:graph[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (ans.size() == n) {
            return ans;
        } else {
            return vector<int>();
        }
    }
};
