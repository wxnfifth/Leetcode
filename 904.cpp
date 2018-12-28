class Solution {
public:
    int totalFruit(vector<int>& tree) {
        //max 2 types array
        //use map to maintain a window
        map<int,int> fruit_count;//map->first is fruit type id, map->second is fruit type count, count <= 2
        if (tree.size() == 0) {
            return 0;
        }
        int start = 0;
        int ans = 0;
        for (int i = 0; i < tree.size(); ++i) {
            //put fruit into tree
            fruit_count[tree[i]]++;
            if (fruit_count.size() > 2) {
                while (start <= i) {
                    fruit_count[tree[start]]--;
                    if (fruit_count[tree[start]] == 0) {
                        fruit_count.erase(tree[start]);
                    }
                    start++;
                    if (fruit_count.size() <= 2) {
                        break;
                    }
                }
            }
            //element in [start, i]
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
