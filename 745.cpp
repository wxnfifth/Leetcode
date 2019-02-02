class WordFilter {
    struct Node {
        bool is_leaf = false;
        vector<Node*> next;
        int index = 0;
        Node():next(27, nullptr) {}
        ~Node() {
            for (int i = 0; i < 27; ++i) {
                if (next[i] != nullptr) {
                    delete next[i];
                }
            }
        }
    };
    
    void insert(string s, int index) {
        Node* p = root_;
        for (int i = 0; i < s.length(); ++i) {
            if (p->next[s[i] - 'a'] == nullptr) {
                p->next[s[i] - 'a'] = new Node();
            }
            p = p->next[s[i] - 'a'];
            p->index = index;
        }
        p->is_leaf = true;
    }
    
    int find(string s) {
        Node* p = root_;
        for (int i = 0; i < s.length(); ++i) {
            if (p->next[s[i] - 'a'] == nullptr) {
                return -1;
            }
            p = p->next[s[i] - 'a'];
        }
        return p->index;
    }
    
    Node* root_;
    vector<string> words_;
    
public:
    WordFilter(vector<string> words) {
        //use trie to solve
        root_ = new Node();
        for (int index = 0; index < words.size(); ++index) {
            string w = words[index];
            insert("{" + w, index);
            string suffix = "";
            for (int i = w.length() - 1; i >= 0; --i) {
                suffix = w[i] + suffix;
                insert(suffix + "{" + w, index);
            }
        }   
        words_ = words;
    }
    
    int f(string prefix, string suffix) {
        return find(suffix + "{" + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
 
 
 https://zxi.mytechroad.com/blog/tree/leetcode-745-prefix-and-suffix-search/
 
