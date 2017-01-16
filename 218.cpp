
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> st;//height of rectangle
        
        vector<pair<int,int>> pts;//first is x axis, second is height, negative height for right side of building
        for (auto b:buildings) {
            pts.push_back(make_pair(b[0], -b[2]));
            pts.push_back(make_pair(b[1], b[2]));
        }
        sort(pts.begin(), pts.end());
        st.insert(0);
        vector<pair<int,int>> ans;
        for (auto p:pts) {
            if (p.second < 0) {//left side of building
                st.insert(-p.second);
            } else {//right side of building
                st.erase(st.find(p.second));
            }
            pair<int,int> v;
            v = make_pair(p.first, *st.rbegin());
            if (ans.size() == 0 || ans.back().second != v.second) {
                ans.push_back(v);
            }
        }
        return ans; 
    }
};