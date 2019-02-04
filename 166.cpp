 Fraction to Recurring Decimal class Solution {
public:
    string fractionToDecimal(long long  n, long long d) {
        if (n < 0 && d > 0) {
            return "-" + fractionToDecimal(-n , d);
        }
        if (n > 0 && d < 0) {
            return "-" + fractionToDecimal(n, -d);
        }
        if (n < 0 && d < 0) {
            n = -n;
            d = -d;
        }
        string ans;
        if (n > d) {
            ans += to_string(n / d);
            n %= d;
        } else if (n == d) {
            return "1";
        } else {
            ans += "0";
        }
        if (n == 0) {
            return ans;
        }
        //process fraction
        ans += ".";
        unordered_map<int, int> v;
        string s;
        while (n != 0) {
            if (v.count(n) > 0) {
                //repeated
                s = s.substr(0, v[n]) + "(" + s.substr(v[n])  + ")";
                break;
            } else {
                s += to_string(n * 10 / d);
                v[n] = s.length() - 1;
                n = n * 10 % d;
                //cout << "n " << n << "\n";
            }
        }
        return ans + s;
    }
};
