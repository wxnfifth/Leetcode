class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();
        if (nums.size() == 0) {
            return -1;
        }
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                begin++;
            } else {
                end--;
            }
        }
        return begin;
    }
};
