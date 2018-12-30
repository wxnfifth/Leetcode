class Solution {
    int getFather(int a, vector<int>& father) {
        while (father[a] != a) {
            a = father[a];
        }
        return a;
    }
    void combine(int a, int b, vector<int>& father) {
        int father_a = getFather(a, father);
        int father_b = getFather(b, father);
        father[father_b] = father_a;
    }
    
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        //first find similar words, then check 2 words similarity
        //use union to determin similar words
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_map<string, int> word2id;
        int id = 0;
        for (auto p:pairs) {
            if (word2id.count(p.first) == 0) {
                word2id[p.first] = id++;
            }
            if (word2id.count(p.second) == 0) {
                word2id[p.second] = id++;
            }
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (word2id.count(words1[i]) == 0) {
                word2id[words1[i]] = id++;            
            }
            if (word2id.count(words2[i]) == 0) {
                word2id[words2[i]] = id++;            
            }
        }
        int n = id;//number of words
        vector<int> father(n, -1);
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
        for (auto p:pairs) {
            combine(word2id[p.first], word2id[p.second], father);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (getFather(word2id[words1[i]], father) !=
                getFather(word2id[words2[i]], father)) {
                return false;
            }
        }
        return true;
    }
};
