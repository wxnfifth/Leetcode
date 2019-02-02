class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char,int> mp;
        int ans = 0;
        int begin = 0;
        for (int i = 0; i < s.length(); ++i) {
            mp[s[i]]++;
            while (begin <= i && mp.size() > k) {
                mp[s[begin]]--;
                if (mp[s[begin]] == 0) {
                    mp.erase(s[begin]);
                }
                begin++;
            }
            ans = max(ans, i - begin + 1);
        }
        return ans;
    }
};
