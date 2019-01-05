class Solution {
    int ans = 0;
    string low_;
    string high_;
    void dfs(string s, int len) {
        if (s.length() >= len) {
            if ((s.length() > 1 && s[0] == '0') || s.length() > len) {
                return;
            }
            if ((s.length() == low_.length() && s < low_) ||
                (s.length() == high_.length() && s > high_)) {
                return;
            }
            ans++;
            return;
        }
        dfs("0" + s + "0", len);
        dfs("1" + s + "1", len);
        dfs("8" + s + "8", len);
        dfs("6" + s + "9", len);
        dfs("9" + s + "6", len); 
    }
    
    
public:
    int strobogrammaticInRange(string low, string high) {
        //use recursive method to generate string with length in [len(low), len(high)]
        //for each string, check to make sue it >= low and <= high
        low_ = low;
        high_ = high;
        string s;
        for (int i = low.length(); i <= high.length(); ++i) {
            dfs("", i);
            dfs("1", i);
            dfs("8", i);
            dfs("0", i);
        }
        return ans;
    }
};
