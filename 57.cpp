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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        bool has_inserted = false;
        vector<Interval> ans;
        for (auto interval:intervals) {
            if (interval.start > newInterval.end && !has_inserted) {
                ans.push_back(newInterval);
                ans.push_back(interval);
                has_inserted = true;
            } else if (interval.end < newInterval.start || interval.start > newInterval.end) {
                ans.push_back(interval);
            } else {//current interval has intersection with newInterval
                newInterval.start = min(interval.start, newInterval.start);
                newInterval.end = max(interval.end, newInterval.end);
            }
        }
        if (!has_inserted) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};
