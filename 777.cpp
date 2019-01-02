
class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.length() != end.length()) {
            return false;
        }
        string s, e;
        for (int i = 0; i < start.length(); ++i) {
            if (start[i] != 'X') {
                s += start[i];
            }
            if (end[i] != 'X') {
                e += end[i];
            }
        }
        if (s != e) {
            return false;
        }
        //L in start must be left of L in end
        //R in start must be right of R in end
        int num_start_L = 0;
        int num_start_R = 0;
        int num_end_L = 0;
        int num_end_R = 0;
        for (int i = 0; i < start.length(); ++i) {
            if (start[i] == 'L') {
                num_start_L++;
            } else if (start[i] == 'R'){
                num_start_R++;
            }
            if (end[i] == 'L') {
                num_end_L++;
            } else if (end[i] == 'R') {
                num_end_R++;
            }
            if (num_start_L > num_end_L || num_start_R < num_end_R) {
                return false;
            }
        }
        return num_start_L == num_end_L && num_start_R == num_end_R;
    }
};
