class AutocompleteSystem {
    struct Node {
        map<char, Node*> next;
        bool is_leaf = false;
        int times = 0;
    };

    struct Ele{
        string s;
        int times;
        bool operator<(const Ele& o) const {
            if (times != o.times) {
                return times > o.times;
            }
            return s < o.s;
        }
        Ele(string _s, int _times) {
            s = _s;
            times = _times;
        }
    };

    
    void addWord(string s, int times) {
        Node* t = root;
        for (char c:s) {
            if (t->next.count(c) == 0) {
                t->next[c] = new Node();
            }
            t = t->next[c];
        }
        t->is_leaf = true;
        t->times = times;
    }
            
    void dfs(Node* t, string current, priority_queue<Ele>& que) {
        for (auto p: t->next) {
            dfs(p.second, current + p.first, que);
        }
        if (t->is_leaf) {
            que.push(Ele(current, t->times));
            if (que.size() > 3) {
                que.pop();
            }
        }
    }

    Node* current_node;
    string current_s;
    Node* root;

public:
    //Trie + priority_queue
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new Node();
        for (int i = 0; i < sentences.size(); ++i) {
            addWord(sentences[i], times[i]);
        }
        current_node = root;
        current_s = "";
    }
    
    vector<string> input(char c) {
        //use a priority_queue to find top 3 hot sentences
        //use dfs to search in Trie
        if (c != '#') {
            if (current_node->next.count(c) == 0) {
                current_node->next[c] = new Node();
            }
            current_node = current_node->next[c];
            current_s += c;
            priority_queue<Ele> que;
            dfs(current_node, current_s, que);
            vector<string> ans;
            while (!que.empty()) {
                ans.push_back(que.top().s);
                que.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        } else {
            current_node->is_leaf = true;
            current_node->times += 1;
            current_node = root;
            current_s = "";
            return vector<string>();
        }       
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
