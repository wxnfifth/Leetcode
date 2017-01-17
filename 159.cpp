class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length() == 0) {
            return 0;
        }
        map<char,int> mp;
        int i = 0;
        int j = 0;
        int max_len = 0;
        while (j < s.length()) {
            mp[s[j]]++;
            j++;
            if (mp.size() > 2) {
                while (i < j && mp.size() > 2) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            max_len = max(max_len, j - i);
        }
        return max_len;
        
    }
};