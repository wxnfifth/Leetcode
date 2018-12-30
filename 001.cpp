class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(target - nums[i]) != s.end() && s[target - nums[i]] != i ) {
                return vector<int>{i, s[target-nums[i]]};
            }
        }
        return vector<int>{-1,-1};//should not happen
    }
};
