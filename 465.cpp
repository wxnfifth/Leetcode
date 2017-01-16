//brute force solution
class Solution {
private:
    int ans = INT_MAX;
    void dfs(vector<int>& debts, int start, int count) {
        while (start < debts.size() && debts[start] == 0) {
            start++;
        }
        if (start == debts.size()) {
            ans = min(ans, count);
            return;
        } 
        for (int i = start + 1; i < debts.size(); ++i) {
            if ((debts[start] < 0 && debts[i] > 0) || (debts[start] > 0 && debts[i] < 0)) {
                debts[i] += debts[start];
                dfs(debts, start + 1, count + 1);
                debts[i] -= debts[start];
            }
        }
    }
    
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,int> accounts;
        for (auto t:transactions) {
            accounts[t[0]] -= t[2];
            accounts[t[1]] += t[2];
        }
        vector<int> debts;
        for (auto a:accounts) {
            if (a.second != 0) {
                debts.push_back(a.second);
            }
        }
        
        dfs(debts, 0, 0);
        return ans;
    }
};