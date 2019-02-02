class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        string ans;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                //i now points to [
                int cnt = 0;
                int start_pos = i + 1;
                while (i < s.length()) {
                    if (s[i] == '[') {
                        cnt++;
                    }
                    if (s[i] == ']') {
                        cnt--;
                    }
                    i++;
                    if (cnt == 0) {
                        break;
                    }
                }
                string decode_s = decodeString(s.substr(start_pos, i - start_pos - 1));
                for (int k = 0; k < num; ++k) {
                    ans += decode_s;
                }
            } else {
                while (i < s.length() && isalpha(s[i])) {
                    ans += s[i];
                    i++;
                }
            }
        }
        return ans;
    }
};
