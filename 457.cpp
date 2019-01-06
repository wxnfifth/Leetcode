class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        //for each number, try to move forward and backward, after move, put the number to 0
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            int current = i;
            int next = ((nums[current] + current) % n + n) % n;
            if (next == current) {
                continue;
            }    
            int current_step = nums[current];
            while (current_step * nums[next] > 0 && next != i) {
                    current = next;
                    current_step = nums[current];
                    nums[current] = 0;
                    next = ((current_step + current) % n + n) % n;
            }
            if (next == i) {
                    return true;
            }
            
        }
        return false;
    }
};
