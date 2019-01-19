//dfs to solve
class Solution {
    int ans = 0;
    void dfs(const string& s, int pos) {
        if (pos >= s.length()) {
            ans++;
            return;
        }
        if (s[pos] >= '1' && s[pos] <= '9') {
            dfs(s, pos + 1);
        }
        if ((s[pos] == '1' && pos + 1 < s.length()) ||
            (s[pos] == '2' && pos + 1 < s.length() && s[pos + 1] <= '6')) {
            dfs(s, pos + 2);
        }
    }
    
    
public:
    int numDecodings(string s) {
        //use dfs to try different ways
        dfs(s, 0);
        return ans;
    }
};



class Solution {
    
public:
    int numDecodings(string s) {
        //dp to solve
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.length(); ++i) {
            if (s[i - 1] >= '1' && s[i - 1] <= '9') {
                dp[i] += dp[i - 1];
            }
            if ((i >= 2 && s[i - 2] == '1') ||
                (i >= 2 && s[i - 2] == '2' && s[i - 1] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
};
