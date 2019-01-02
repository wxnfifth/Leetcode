
class Solution {
public:
    int candy(vector<int>& ratings) {
        //from left to right, if right child's rate is higher, assign +1 to right child, if not, assign 1
        //from right to left, if left child's rate higher but candy not more, assign +1 candy to left child
        vector<int> c(ratings.size(), 0);
        c[0] = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i - 1] < ratings[i]) {
                c[i] = c[i - 1] + 1;
            } else {
                c[i] = 1;
            }
        }
        for (int i = ratings.size() - 1; i >= 1; --i) {
            if (c[i - 1] <= c[i] && ratings[i - 1] > ratings[i]) {
                c[i - 1] = c[i] + 1;                
            }
        }
        return accumulate(c.begin(), c.end(), 0);
    }
};
