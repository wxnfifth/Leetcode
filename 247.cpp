class Solution {
    vector<string> ans;
    void dfs(string path, int pos, int n) {
        if (pos == n / 2) {
            if (n % 2 == 1) {
                ans.push_back(path + "0");
                ans.push_back(path + "1");
                ans.push_back(path + "8");
            } else {
                ans.push_back(path);
            }
            return;
        }
        if (pos != 0) {
            dfs(path + "0", pos + 1, n);
        }
        dfs(path + "1", pos + 1, n);
        dfs(path + "8", pos + 1, n);
        dfs(path + "6", pos + 1, n);
        dfs(path + "9" , pos + 1, n);
    }
    
    
public:
    vector<string> findStrobogrammatic(int n) {
        //dfs to generate
        string path = "";
        dfs(path, 0, n);
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < n / 2; ++j) {
                char c=ans[i][n / 2 - 1 - j]; 
                if (c == '0' || c == '1' || c == '8') {
                    ans[i] += c;
                } else if (c == '6') {
                    ans[i] += '9';
                } else if (c == '9') {
                    ans[i] += '6';
                }
            }
        }
        return ans;
    }
};
