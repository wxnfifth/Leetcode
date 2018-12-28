class Solution {
    int to_min(string s) {
        return ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
    }
public:
    string nextClosestTime(string time) {
        //enumerate all posibility
        set<int> digits;
        digits.insert(time[0]-'0');
        digits.insert(time[1]-'0');
        digits.insert(time[3]-'0');
        digits.insert(time[4]-'0');
        int current_min = to_min(time);
        string result;
        int closest = INT_MAX;
        for (int d0: digits) {
            if (d0 >= 3) {
                continue;
            }
            for (int d1: digits) {
                if (d0 * 10 + d1 >= 24) {
                    continue;
                }
                for (int d2: digits) {
                    if (d2 >= 6) {
                        continue;
                    }
                    for (int d3: digits) {
                        if (d2 * 10 + d3 >= 60) {
                            continue;
                        }
                        int next = (d0 * 10 + d1) * 60 + d2 * 10 + d3;
                        if (next - current_min <= 0) {
                            next += 24 * 60;
                        }
                        string tmp_s = to_string(d0) + to_string(d1) + ":" + to_string(d2) + to_string(d3);
                        //cout << tmp_s << " " << next - current_min << "\n";
                        if (closest > next - current_min) {
                            closest = next - current_min;
                            result = tmp_s;
                        }
                    }
                }
            }
        }
        return result;
    }
};
