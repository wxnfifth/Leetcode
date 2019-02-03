/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> v;//first is time, second is -1 for end, 1 for start
        for (Interval& i:intervals) {
            v.push_back(make_pair(i.start, 1));
            v.push_back(make_pair(i.end, -1));
        }
        sort(v.begin(), v.end());
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < v.size(); ++i) {
            cnt += v[i].second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
