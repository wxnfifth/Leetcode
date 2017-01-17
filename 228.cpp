class Solution {
public:
    //scan the array and put the results
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<string>();
        }
        int start = nums[0];
        int end = nums[0];
        vector<string> ans; 
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > end + 1) {
                if (start == end) {
                    ans.push_back(to_string(start));
                } else {
                    ans.push_back(to_string(start) + "->" + to_string(end));
                }
                start = end = nums[i];
            } else if (nums[i] == end + 1) {
                end++;
            }
        }
        if (start == end) {
            ans.push_back(to_string(start));
        } else {
            ans.push_back(to_string(start) + "->" + to_string(end));
        }
        return ans;
    }
};