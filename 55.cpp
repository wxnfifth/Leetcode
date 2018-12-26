class Solution {
public:
    bool canJump(vector<int>& nums) {
        //from start, jump to next max value
        int reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (reach < i) {
                return false;
            }
            if (reach >= nums.size() - 1) {
                return true;
            }
            reach = max(reach, i + nums[i]);
        }
      return false;//should not reach here
    }
};
