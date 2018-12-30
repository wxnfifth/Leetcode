class Solution {
    
    double bfs(map<string, map<string, double>>& graph, pair<string,string> q) {
        if (graph[q.first].empty() || graph[q.second].empty()) {
            return -1;
        }
        if (graph[q.first].count(q.second) > 0) {
            return graph[q.first][q.second];
        }
        //find from first
        queue<string> que;
        map<string, double> value;//record visited or not
        que.push(q.first);
        value[q.first] = 1;
        while (!que.empty()) {
            string u = que.front();
            que.pop();
            double v = value[u];
            if (u == q.second) {
                return 1 / v;
            }
            for (auto neighbor:graph[u]) {
                if (value.count(neighbor.first) == 0) { // not visited
                    que.push(neighbor.first);
                    value[neighbor.first] = v / neighbor.second;
                }
            }
        }
        return -1;        
    }
    
    
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        // for each A /B = k, we have edge a->b, b->a
        // given a query a a->c, we find the path from a to c
        map<string, map<string, double>> graph; //graph[a][b] = d is an edge
        for (int i = 0; i < equations.size(); ++i) {
            auto e = equations[i];
            double v = values[i];
            graph[e.first][e.second] = v;
            graph[e.second][e.first] = 1 / v;
            graph[e.first][e.first] = 1;
            graph[e.second][e.second] = 1;
        }
        //for each query, use bfs to find a path
        vector<double> ans;
        for (auto q:queries) {
            ans.push_back(bfs(graph, q));
        }
        return ans;
    }
};
