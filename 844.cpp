class Solution {
public:
    bool backspaceCompare(string S, string T) {
        //o(1) space solution
        //directly modify the string, use an index to simulate stack
        int s_head = 0;
        int t_head = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '#') {
                if (s_head > 0) {
                    s_head--;
                }
            } else {
                S[s_head++] = S[i];
            }
        }
        for (int i = 0; i < T.length(); ++i) {
            if (T[i] == '#') {
                if (t_head > 0) {
                    t_head--;
                }
            } else {
                T[t_head++] = T[i];
            }
        }
        if (s_head != t_head) {
            return false;
        }
        for (int i = 0; i < s_head; ++i) {
            if (S[i] != T[i]) {
                return false;
            }
        }
        return true;
    }
};
