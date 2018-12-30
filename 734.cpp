class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_set<string> similar;
        for (auto p:pairs) {
            similar.insert(p.first + "#" + p.second);
            similar.insert(p.second + "#" + p.first);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] != words2[i] && similar.find(words1[i] + "#" + words2[i]) == similar.end()) {
                return false;
            }
        }
        return true;
        
    }
};
