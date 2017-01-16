class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //four corners occurs once and all sub area equal to the square area
        //other coners occurs even times
        unordered_set<string> corners;
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        int max_x = INT_MIN;
        int max_y = INT_MIN;
        int total_area = 0;
        for (auto r: rectangles) {
            total_area += (r[2] - r[0]) * (r[3] - r[1]);
            string c0 = to_string(r[0]) + " " + to_string(r[1]);
            string c1 = to_string(r[0]) + " " + to_string(r[3]);
            string c2 = to_string(r[2]) + " " + to_string(r[1]);
            string c3 = to_string(r[2]) + " " + to_string(r[3]);
            if (corners.find(c0) == corners.end()) {
                corners.insert(c0);
            } else {
                corners.erase(c0);
            }
            if (corners.find(c1) == corners.end()) {
                corners.insert(c1);
            } else {
                corners.erase(c1);
            }
            if (corners.find(c2) == corners.end()) {
                corners.insert(c2);
            } else {
                corners.erase(c2);
            }
            if (corners.find(c3) == corners.end()) {
                corners.insert(c3);
            } else {
                corners.erase(c3);
            }
            min_x = min(min_x, r[0]);
            min_y = min(min_y, r[1]);
            max_x = max(max_x, r[2]);
            max_y = max(max_y, r[3]);
        }
        cout << corners.size() << "\n";
        cout << min_x << " " << min_y << "\n";
        cout << max_x << " " << max_y << "\n";
        if (corners.size() == 4 && 
            corners.find(to_string(min_x) + " " + to_string(min_y)) != corners.end() &&
            corners.find(to_string(min_x) + " " + to_string(max_y)) != corners.end() &&
            corners.find(to_string(max_x) + " " + to_string(max_y)) != corners.end() &&
            corners.find(to_string(max_x) + " " + to_string(min_y)) != corners.end() &&
            (max_x - min_x) * (max_y - min_y) == total_area) {
                return true;
        }
        return false;
    }
};