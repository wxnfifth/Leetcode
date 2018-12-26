class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //3 sum's solution complexity is n^2
        //add another loop above n^2
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int sum = target - nums[i] - nums[j];
                int k = 0;
                int t = j - 1;
                while (k < t) {
                    if (nums[k] + nums[t] < sum) {
                        k++;
                    } else if (nums[k] + nums[t] > sum) {
                        t--;
                    } else {
                        st.insert(vector<int>{nums[k], nums[t], nums[j], nums[i]});
                        k++;
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};
