class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find a decreasing sequence from pos to end of nums
        //reverse the sequence, and insert nums[pos - 1] into the sequence
        int pos = nums.size() - 1;
        while (pos - 1 >= 0 && nums[pos -1] >= nums[pos]) {
            pos--;
        }
        //reverse [pos, nums.end())
        int i = pos;
        int j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        if (pos == 0) {
            return;
        }
        //insert nums[pos - 1] into the sequence
        i = pos;
        while (i < nums.size() && nums[i] <= nums[pos - 1]) {
            i++;
        }
        swap(nums[i], nums[pos - 1]);
    }
};
