class Solution {
    int dis(const pair<int,int>& a, const pair<int,int>& b) {
        return (a.first - b.first) * (a.first - b.first) + 
               (a.second - b.second) * (a.second - b.second);
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        //for each i
        int ans = 0;
        for (auto p:points) {
            //find number of pairs distance equal to i
            unordered_map<int, int> mp;//first is square distance, second is number of points
            for (int j = 0; j < points.size(); ++j) {
                mp[dis(p, points[j])]++;
            }
            for (auto m:mp) {
                if (m.second >= 2) {
                    ans += m.second * (m.second - 1);
                }
            }
        }
        return ans;
    }
};
