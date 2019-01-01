class Solution {
    
    struct Node {
        int index;
        string source;
        string target;
        bool operator<(const Node& o) const {
            return index < o.index;
        }
        Node(int _index, string _source, string _target) {
            index = _index;
            source = _source;
            target = _target;
        }
    };
    
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        //sort input according to indexes
        vector<Node> p;
        for (int i = 0; i < indexes.size(); ++i) {
            p.push_back(Node(indexes[i], sources[i], targets[i]));
        }
        sort(p.begin(), p.end());
        //assume indexes is sorted
        int pos = 0;
        string ans;
        for (int i = 0; i < S.length();) {
            if (i == p[pos].index) {
                //check sources[i] in indexes
                bool flag = true;
                if (i + p[pos].source.length() > S.length()) {
                    flag = false;
                } else {
                    for (int j = i; j < i + p[pos].source.length(); ++j) {
                        if (S[j] != p[pos].source[j - i]) {
                            flag = false;
                            break;
                        }   
                    }        
                }
                if (flag) {
                    ans += p[pos].target;
                    i += p[pos].source.length();
                } else {
                    ans += S[i];
                    i++;
                }
                pos++;
            } else {
                ans += S[i];
                i++;
            }
        }
        return ans;
        
    }
};
