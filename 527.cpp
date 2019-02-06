class Solution {
    struct Node{
        unordered_map<char, Node*> next;
        int count = 0;
        Node() {
        }
        ~Node() {
            for (auto n:next) {
                if (n.second != nullptr) {
                    delete n.second;
                }
            }
        }
    };
    Node* root;
    
    string getSimpleAbbr(string s) {
        if (s.length() <= 3) {
            return s;
        }
        return s[0] + to_string(s.length() - 2) + s[s.length() - 1];
    }
    
    void insert(int word_id, string s) {
        s = getSimpleAbbr(s) + "[" + s;
        //cout << "s " << s << "\n";
        Node* p = root;
        for (int i = 0; i < s.length(); ++i) {
            if (p->next.count(s[i]) == 0) {
                p->next[s[i]] = new Node();
            }
            p = p->next[s[i]];
            p->count++;
        }
    }
    string getAbbr(string s) {
        string pre = getSimpleAbbr(s) + "[";
        s = pre + s;
        Node* p = root;
        int i = 0;
        string ans;
        for (; i < s.length(); ++i) {
            p = p->next[s[i]];
            ans += s[i];
            if (p->count == 1 && i >= pre.length()) {
                i++;
                break;
            }
        }
        //cout <<"ans " << ans << "\n";
        if (i < s.length() - 2) {
            ans += to_string(s.length() - i - 1) + s[s.length() - 1];
            //cout << "i " << i << " ans " << ans << "\n";
        } else {
            ans += s.substr(i);
        }
        ans = ans.substr(pre.length());
        return ans;
    }
    
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        //make trie for a word ,inter, set internal-> i6l{internal
        //insert string into trie and at leaf node, save the word
        root = new Node();
        for (int i = 0; i < dict.size(); ++i) {
            insert(i, dict[i]);
        }
        vector<string> ans;
        for (int i = 0; i < dict.size(); ++i) {
            ans.push_back(getAbbr(dict[i]));
        }
        return ans;
    }
};
