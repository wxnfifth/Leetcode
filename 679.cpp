class Solution {
    bool flag = false;
    vector<double> getNextNums(const vector<double>& nums, int i, double d) {
        vector<double> next_nums;
        for (int j = 0; j < i; ++j) {
           next_nums.push_back(nums[j]);
        }
        next_nums.push_back(d);
        for (int j = i + 2; j < nums.size();++j) {
           next_nums.push_back(nums[j]);
        }
        return next_nums;
    }
    
    void enumerate(vector<double> nums) {
        if (flag) {
            return;
        }
        if (nums.size() == 1) {
            if (fabs(nums[0] - 24) < 1e-6) {
                flag = true;
            }
            return;
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            enumerate(getNextNums(nums, i, nums[i] * nums[i + 1]));
            if (nums[i + 1] != 0) {
                enumerate(getNextNums(nums, i, nums[i] / nums[i + 1]));
            }
            enumerate(getNextNums(nums, i, nums[i] + nums[i + 1]));
            enumerate(getNextNums(nums, i, nums[i] - nums[i + 1]));           
        }   
    }
    
public:
    bool judgePoint24(vector<int>& nums) {
        //try to enumerate numbers and operators and order of operations
        vector<double> nums_double;
        for (int i = 0; i < nums.size(); ++i) {
            nums_double.push_back(nums[i]);
        }
        for (int i = 0; i < 4 * 3 * 2; ++i) {
            enumerate(nums_double);
            next_permutation(nums_double.begin(),nums_double.end());        
        }

        return flag;
    }
};
