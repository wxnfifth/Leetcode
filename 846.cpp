class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> hand_count;
        for (int h:hand) {
            hand_count[h]++;
        }
        for (auto itr = hand_count.begin(); itr != hand_count.end(); ++itr) {
            if (itr->second == 0) {
                continue;
            }
            int num = itr->second;
            itr->second = 0;
            auto itr_j = next(itr);
            for (int j = 1; j < W; ++j, itr_j++) {
                if (itr_j != hand_count.end() && itr_j->first == prev(itr_j)->first + 1 && itr_j->second >= num) {
                    itr_j->second -= num;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
