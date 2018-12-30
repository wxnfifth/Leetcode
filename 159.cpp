//new solution
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //use a window to count how many distinct characters
        map<char, int> window;// window->first is character, window->second is count
        int len = 0;
        int start = 0;
        int end = 0; // window is [start, end] 
        while (end < s.length()) {
            window[s[end]]++;
            while (start <= end && window.size() > 2) {
                window[s[start]]--;
                if (window[s[start]] == 0) {
                    window.erase(s[start]);
                }
                start++;
            }
            len = max(len, end - start + 1);
            end++;
        }
        return len;
    }
};
        


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
