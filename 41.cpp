class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //put the number into the relative index
        //put 3 in index 2, put 1 in index 0
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] - 1 == i || nums[i] <= 0 || nums[i] > nums.size()) {
                continue;
            }
            while (nums[i] - 1 != i && nums[i] > 0 && nums[i] <= nums.size()) {
                if (nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                swap(nums[i] , nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] - 1 != i) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
