//first solution, 79ms
//solved it after read the answer
class Solution {
private:
    bool canWinHelper(string s) {
        for (int i = 1; i < s.length(); ++i) {
            if (s[i-1] == '+' && s[i] == '+') {
                s[i-1] = '-';
                s[i] = '-';
                bool win = !canWinHelper(s);
                s[i-1] = '+';
                s[i] = '+';
                if (win) {
                    return true;
                }
            }
        }    
        return false;
    }
public:
    bool canWin(string s) {
        return canWinHelper(s);
    }
};

//second solution, 19ms
//with memorization
class Solution {
private:
    unordered_map<string, bool> mp;
    
    bool canWinHelper(string s) {
        if (mp.find(s) != mp.end()) {
            return mp[s];
        }
        for (int i = 1; i < s.length(); ++i) {
            if (s[i-1] == '+' && s[i] == '+') {
                s[i-1] = '-';
                s[i] = '-';
                bool win = !canWinHelper(s);
                s[i-1] = '+';
                s[i] = '+';
                if (win) {
                    mp[s] = true;
                    return true;
                }
            }
        }   
        mp[s] = false;
        return false;
    }
public:
    bool canWin(string s) {
        return canWinHelper(s);
    }
};