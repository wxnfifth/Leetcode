//modified a little bit
class LRUCache {
    int capacity_;
    unordered_map<int, list<pair<int,int>>::iterator> mp;//first is key, second is pos in que
    list<pair<int,int>> lst;//first of pair is key, second of pair is value, use list for efficient delete element

public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        } else {
            int value = mp[key]->second;
            lst.erase(mp[key]);
            lst.push_back(make_pair(key,value));
            auto itr = lst.end();
            itr--;
            mp[key] = itr;
            return value;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            lst.erase(mp[key]);
        }
        lst.push_back(make_pair(key,value));
        auto itr = lst.end();
        itr--;
        mp[key] = itr;
        if (lst.size() > capacity_) {
            mp.erase(lst.front().first);
            lst.pop_front();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */