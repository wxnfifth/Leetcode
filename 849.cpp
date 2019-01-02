class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDis = 0;
        int pre = -1;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                if (pre == -1) {
                    maxDis = max(maxDis,i);
                } else if (i - pre >= 2) {
                    maxDis = max(maxDis, (i - pre) / 2);
                }
                pre = i;
            }
        }
        maxDis = max(maxDis, (int)seats.size() - 1 - pre);
        return maxDis;
    }
};
