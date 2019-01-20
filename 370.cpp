class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> v(length, 0);
        for (auto p: updates) {
            v[p[0]] += p[2];
            if (p[1] + 1 < length) {
                v[p[1] + 1] -= p[2];
            }
        }
        for (int i = 1; i < length; ++i) {
            v[i] += v[i - 1];
        }
        return v;
    }
};
