class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        long long p = lower;
        int i = 0;
        while (p <= upper && i < nums.size()) {
            if (nums[i] < p) {
                i++;
            } else if (nums[i] == p) {
                i++;
                p++;
            } else {
                //range [p, nums[i] - 1]
                if (nums[i] - 1 == p) {
                    ans.push_back(to_string(p));
                } else {
                    ans.push_back(to_string(p) + "->" + to_string(nums[i] - 1));
                }
                p = (long long)nums[i] + 1;
                i++;
            }
        }
        if (p <= upper) {
            if (upper == p) {
                ans.push_back(to_string(upper));
            } else { 
                ans.push_back(to_string(p) + "->" + to_string(upper));
            }
        }
        return ans;
    }
};
