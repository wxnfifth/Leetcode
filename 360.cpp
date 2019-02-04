class Solution {
    int func(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (a == 0) {
            vector<int> ans;
            for (int x:nums) {
                ans.push_back(func(x, a, b, c));
            }
            if (b >= 0){
                return ans;
            } else {
                reverse(ans.begin(), ans.end());
                return ans;
            }
        }
        //f'(x) = 2ax + b, x = -b / 2a is middle 
        vector<int> left;
        vector<int> right;
        double middle = -1.0 * b / 2.0 / a;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < middle) {
                left.push_back(func(nums[i], a, b, c));
            } else {
                right.push_back(func(nums[i],a ,b, c));
            }
        }
        if (a > 0) {
            reverse(left.begin(), left.end());
        } else {
            reverse(right.begin(), right.end());
        }
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < left.size() || j < right.size()) {
            if (j == right.size() || (i < left.size() && left[i] < right[j])) {
                ans.push_back(left[i]);
                i++;
            } else {
                ans.push_back(right[j]);
                j++;
            }
        }
        return ans;
    }
};
