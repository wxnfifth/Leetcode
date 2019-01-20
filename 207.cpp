class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //topological sort
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (auto p:prerequisites) {
            graph[p.second].push_back(p.first);
            in_degree[p.first]++;
        }
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            cnt++;
            q.pop();
            for (int neigh:graph[u]) {
                in_degree[neigh]--;
                if (in_degree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        return cnt == numCourses;
    }
};
