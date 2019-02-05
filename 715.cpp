class RangeModule {
    vector<pair<int,int>> intervals;
    
public:
    RangeModule() {
        
        
    }
    
    void addRange(int left, int right) {
        vector<pair<int,int>> new_intervals;
        int i = 0;
        for (; i < intervals.size(); ++i) {
            if (intervals[i].second < left) {
                new_intervals.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].first > right) {
                break;
            }
            //has intersection
            left = min(left, intervals[i].first);
            right = max(right, intervals[i].second);
        }
        new_intervals.push_back(make_pair(left,right));
        while (i < intervals.size()) {
            new_intervals.push_back(intervals[i]);
            ++i;
        }
        intervals = new_intervals;
        //cout << "insert\n";
        //for (auto p:intervals) {
        //    cout << "[" << p.first << " " << p.second << "]" << "\n";
        //}
    }
    
    bool queryRange(int left, int right) {
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].first <= left && intervals[i].second >= right) {
                return true;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        vector<pair<int,int>> new_intervals;
        for (int i = 0;i < intervals.size(); ++i) {
            if (intervals[i].second <= left || intervals[i].first >= right) {
                new_intervals.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].second <= right) {
                if (intervals[i].first < left) {
                    new_intervals.push_back(make_pair(intervals[i].first, left));
                }
            } else {
                if (intervals[i].first < left) {
                    new_intervals.push_back(make_pair(intervals[i].first, left));
                }
                new_intervals.push_back(make_pair(right, intervals[i].second));
            }
        }
        intervals = new_intervals;
        //cout << "remove\n";
        //for (auto p:intervals) {
        //    cout << "[" << p.first << " " << p.second << "]" << "\n";
        //}
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
