class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k <= 0) {
            return str;
        }
        //use priority_queue
        vector<int> count(128, 0);
        for (char c:str) {
            count[c]++;
        }
        priority_queue<pair<int,char>> q;//top is chars occurs most times
        for (char c = 'a'; c <= 'z'; ++c) {
            if (count[c] > 0) {
                            q.push(make_pair(count[c], c));

            }
        }
        string ans;
        while (!q.empty()) {
            //if less than k chars
            if (q.size() < k) {
                //put them into Result
                while (!q.empty()) {
                    if (q.top().first > 1) {
                        return "";//can not get result
                    }
                    ans += q.top().second;
                    q.pop();
                }
            } else {
                vector<pair<int,char>> v;
                for (int i = 0; i < k; ++i) {
                    auto p = q.top();
                    q.pop();
                    ans += p.second;
                    p.first--;
                    if (p.first > 0) {
                        v.push_back(p);
                    }
                }
                for (int i = 0; i < v.size(); ++i) {
                    q.push(v[i]);
                }
            }
        }
        return ans;

    }
};
