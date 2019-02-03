class Solution {
    mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis;
    vector<int> sum;
public:
    Solution(vector<int> w) {
        int s = 0;
        sum.push_back(s);
        for (int i = 0; i < w.size(); ++i) {
            s += w[i];
            sum.push_back(s);
        }
        dis = uniform_int_distribution<>(0, s - 1);
    }
    
    int pickIndex() {
        int r = dis(gen);
        return upper_bound(sum.begin(), sum.end(), r) - sum.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
