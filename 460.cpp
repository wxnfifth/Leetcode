class LFUCache {
    struct Node {
        int key;
        int value;
        int count;
        Node(int _key, int _value) {
            key = _key;
            value = _value;
            count = 1;
        }
    };
    unordered_map<int, list<Node>::iterator> mp;//first is key, second is position in list
    list<Node> lst;
    int capacity_;
    
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (mp.count(key) > 0) {
            int value = mp[key]->value;
            mp[key]->count++;
            auto itr = next(mp[key]);
            //move forward till itr->count > mp[key]->count
            while (itr != lst.end() && itr->count <= mp[key]->count) {
                itr++;
            }
            auto new_position = lst.insert(itr, *mp[key]);
            lst.erase(mp[key]);
            mp[key] = new_position;
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.count(key) > 0) {
            mp[key]->count++;
            mp[key]->value = value;
            auto itr = next(mp[key]);
            while (itr != lst.end() && itr->count <= mp[key]->count) {
                itr++;
            }
            auto new_position = lst.insert(itr, *mp[key]);
            lst.erase(mp[key]);
            mp[key] = new_position;
        } else if (capacity_ > 0) {
            if (lst.size() >= capacity_) {
                mp.erase(lst.begin()->key);
                lst.erase(lst.begin());        
            }
            Node n = Node(key, value);
            auto itr = lst.begin();
            while (itr != lst.end() && itr->count <= 1) {
                itr++;
            }
            auto new_position = lst.insert(itr, n);
            mp[key] = new_position;
            //delete front
        }
        
    }
};
// capacity is 2
// [1,1]

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
