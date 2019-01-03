465. Optimal Account Balancing
//almost same
class Solution {
    map<int,int> accounts;//account.first is the id, account.second is person's balance
    int min_transfers = INT_MAX;

    void dfs(vector<int>& v, int pos, int num) {
        if (pos >= v.size()) {
            min_transfers = min(min_transfers, num);
            return;
        }
        if (v[pos] == 0) {
            dfs(v, pos + 1, num);
            return;
        }
        for (int i = pos + 1; i < v.size(); ++i) {
            if ((v[i] > 0 && v[pos] < 0) ||
                (v[i] < 0 && v[pos] > 0)) {
                    int tmp = v[pos];
                v[pos] -= tmp;//v[pos] is 0 now
                v[i] += tmp;
                //not i!!, because between pos and i is not settled
                dfs(v, pos + 1, num + 1);
                v[pos] += tmp;
                v[i] -= tmp;
            }
        }
    }

public:
    int minTransfers(vector<vector<int>>& transactions) {
        //first count each person's balance
        for (auto& t:transactions) {
            accounts[t[0]] -= t[2];
            accounts[t[1]] += t[2];
        }
        //dfs to find minTransfers 
        vector<int> v;
        for (auto a:accounts) {
            v.push_back(a.second);
        }
        int num = 0;
        dfs(v, 0, 0);
        return min_transfers;
    }
};

//2017's solution, brute force solution
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
