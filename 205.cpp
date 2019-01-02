class Solution {
public:
bool isIsomorphic(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }
    map<char,char> mp;//map char in a to char in b
    set<char> used_in_b;//make sure it's one to one map, record char occurance in b
    for (int i = 0; i < a.length(); ++i) {
        if (mp.count(a[i]) > 0) {
            if (b[i] != mp[a[i]]) {
                return false;
            }
        } else {
            if (used_in_b.count(b[i]) > 0) {
                return false;
            }
            mp[a[i]] = b[i];
            used_in_b.insert(b[i]);
        }
    }
    return true;
}
};
