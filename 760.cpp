class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> M;
        for (int i = 0; i < B.size(); ++i){
            M[B[i]] = i;
        }
        for (auto a:A){
            res.push_back(M[a]);
        }
        return res;
    }
};
