class Solution {
    vector<vector<int>> ans;
    
    void dfs(vector<int>& candidates, vector<int> path, int pos, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (pos >= candidates.size()) {
            return;
        }
        for (; pos < candidates.size(); ++pos) {
            if (target - candidates[pos] < 0) {
                continue;
            }
            path.push_back(candidates[pos]);
            dfs(candidates, path, pos, target - candidates[pos]);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, path, 0, target);
        return ans;
    }
};
