class Solution {
    vector<pair<char,int>> string2group(string S) {
        vector<pair<char,int>> v;
        int i = 0;
        while (i < S.length()) {
            int i_start = i;
            while (i + 1 < S.length() && S[i + 1] == S[i]) {
                i++;
            }
            i++;
            v.push_back(make_pair(S[i_start], i - i_start));
        }
        return v;        
    }
public:
    int expressiveWords(string S, vector<string>& words) {
        //put s -> groups
        vector<pair<char,int>> group_S = string2group(S);
        int ans = 0;
        for (string w:words) {
            auto group_w = string2group(w);
            if (group_S.size() != group_w.size()) {
                continue;
            }
            bool flag = true;
            for (int i = 0; i < group_S.size(); ++i) {
                if (group_S[i].first == group_w[i].first) {
                    if (group_S[i].second <= 2 && group_S[i].second != group_w[i].second) {
                        flag = false;
                        break;
                    } else if (group_S[i].second > 2 && group_S[i].second < group_w[i].second) {
                        flag = false;
                        break;
                    }
                } else {
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};
