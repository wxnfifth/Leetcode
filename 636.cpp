class Solution {
    void getInfo(string s, int& id, string& o, int& t) {
        int i = 0;
        id = 0;
        while (i < s.length() && s[i] != ':') {
            id = id * 10 + s[i] - '0';
            i++;
        }
        i++;
        o = "";
        while (i < s.length() && s[i] != ':') {
            o += s[i];
            i++;
        }
        i++;
        t = 0;
        while (i < s.length()) {
            t = t * 10 + s[i] - '0';
            i++;
        }
    }
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<pair<int,int>> stk;//id,t
        for (string s:logs) {
            int id;
            string o;
            int t;
            getInfo(s, id, o, t);
            if (o == "start") {
                if (!stk.empty()) {
                    ans[stk.top().first] += t - 1 - stk.top().second;
                }
                stk.push(make_pair(id,t - 1));
            } else {
                ans[stk.top().first] += t - stk.top().second;
                stk.pop();
                if (!stk.empty()) {
                    stk.top().second = t;
                }
            }
        }
        return ans;
    }
};
