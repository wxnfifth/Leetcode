class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int d = digits[i] + carry;
            if (d >= 10) {
                d -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.push_back(d);
        }
        if (carry > 0) {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
