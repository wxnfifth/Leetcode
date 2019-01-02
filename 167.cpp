class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0;
        int second = numbers.size() - 1;
        while (first < second) {
            if (numbers[first] + numbers[second] < target) {
                first++;
            } else if (numbers[first] + numbers[second] > target) {
                second--;
            } else {
                return vector<int>{first + 1,second + 1};
            }
        }
        return vector<int>{-1,-1};//should not happen
    }
};
