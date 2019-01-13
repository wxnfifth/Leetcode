/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    int findGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return findGCD(b, a % b);
    }
    
public:
    int maxPoints(vector<Point>& points) {
        //pick one point as origin
        //other points subtract and get ratio a/b, gcd to find min representation 
        //to avoid overflow
        if (points.size() <= 2) {
            return points.size();
        }
        int ans = 1;
        for (int origin = 0; origin < points.size(); ++origin) {
        Point o = points[origin];
        unordered_map<string, int> mp;//key is a+'#'+b for min representation, value is number of points
        int origin_points = 0;
        for (int i = 0; i < points.size(); ++i) {
            int diff_x = points[i].x - o.x;
            int diff_y = points[i].y - o.y;
            if (diff_x == 0 && diff_y == 0) {
                origin_points++;
            } else {          
                int gcd = findGCD(diff_x, diff_y);
                diff_x /= gcd;
                diff_y /= gcd;
                mp[to_string(diff_x) + "#" + to_string(diff_y)]++;            
            }
        }
        ans = max(ans, origin_points);
        for (auto m:mp) {
            if (m.second + origin_points > ans) {
                ans = m.second + origin_points;
            }
        }
        }
        return ans;
    }
};
