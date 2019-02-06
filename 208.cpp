class Trie {
    struct Node{
        Node* next[26];
        bool is_word = false;
        Node() {
            for (int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
        }
        ~Node() {
            for (int i = 0; i < 26; ++i) {
                if (next[i] != nullptr) {
                    delete next[i];
                }
            }
        }
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for (int i = 0; i < word.length(); ++i) {
            if (p->next[word[i] - 'a'] == nullptr) {
                p->next[word[i] - 'a'] = new Node();
            }
            p = p->next[word[i] - 'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for (int i = 0; i < word.length(); ++i) {
            if (p->next[word[i] - 'a'] == nullptr) {
                return false;
            }
            p = p->next[word[i] - 'a'];
        }
        return p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (p->next[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            p = p->next[prefix[i] - 'a'];
        }
        return true;
    }
    ~Trie() {
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
