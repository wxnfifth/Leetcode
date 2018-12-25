class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //n^2 complexity
        //1. sort the array, nlogn
        //2. for each number, compute b = target - number
        //3. find 2 numbers in array closest to b, O(n) for each b
        sort(nums.begin(), nums.end());
        int closest_diff = INT_MAX;
        int sum = 0;
        for (int k = 0; k < nums.size(); ++k) {
            int b = target - nums[k];
            int i = 0;
            int j = k - 1;
            while (i < j) {
                int diff = abs(b - nums[i] - nums[j]);
                if (closest_diff > diff) {
                    closest_diff = diff;
                    sum = nums[i] + nums[j] + nums[k];
                }
                if (nums[i] + nums[j] > b) {
                    j--;
                } else {
                    i++;
                }
            }
        }
        return sum;
        
    }
};
