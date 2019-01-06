class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        //sort and enumerate each word
        //sort(d.begin(), d.end(), cmp);
        string ans = "";
        for (string ds: d) {
            if (ds.length() > s.length()) {
                continue;
            }
            int is = 0;
            int id = 0;
            while (is < s.length() && id < ds.length()) {
                if (s[is] == ds[id]) {
                    is++;
                    id++;
                } else {
                    is++;
                }
            }
            if (id == ds.length()) {
                if (ds.length() > ans.length()) {
                    ans = ds;
                } else if (ds.length() == ans.length()) {
                    ans = min(ans, ds);
                }
            }
        }
        return ans;
    }
};
