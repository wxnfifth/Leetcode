class Solution {    
public:
    string findContestMatch(int n) {
        //solve by a recursive method
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = to_string(i + 1);
        }
        int len = n;
        while (len >= 2) {
            //cout << "len " << len << "\n";
            for (int i = 0; i < len / 2; ++i) {
                v[i] = "(" + v[i] + "," + v[len - 1 - i] + ")";    
            }
            len /= 2;
        }
        return v[0];
    }
};
