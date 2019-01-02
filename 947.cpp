class Solution {
    int getFather(int a, vector<int>& father) {
        while (father[a] != a) {
            a = father[a];
        }
        return a;
    }

    void unionSet(int a, int b, vector<int>& father) {
        if (father[a] == -1) {
            father[a] = a;
        }
        if (father[b] == -1) {
            father[b] = b;
        }
        int father_a = getFather(a, father);
        int father_b = getFather(b, father);
        father[father_a] = father_b;
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        //for each connected component, if the component size i m, we can remove m - 1 stones
        //we count number of stones and minus number of components
        //use union-set to find number of components
        //stones share same row or column is in the same set
        vector<int> father(20000, -1);
        for (vector<int> s:stones) {
            unionSet(s[0], s[1] + 10000, father);
        }
        int num_components = 0;
        set<int> components;
        for (int i = 0; i < father.size(); ++i) {
            if (father[i] != -1) {
                components.insert(getFather(i, father));
            }
        }
        return stones.size() - components.size();
    }
};
