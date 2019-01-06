class LRUCache {
    int capacity_;
    unordered_map<int, list<pair<int,int>>::iterator> mp;//first is key, second is position in the list
    list<pair<int,int>> lst;//first is key, second is value
    
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (mp.count(key) > 0) {
            int value = mp[key]->second;
            //put the mp[key] position to last position
            lst.push_back(make_pair(key, value));
            //erase origin position in lst
            lst.erase(mp[key]);
            mp[key] = prev(lst.end());
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.count(key) > 0) {
            lst.push_back(make_pair(key,value));
            lst.erase(mp[key]);
            mp[key] = prev(lst.end());
        } else {
            //insert new value
            lst.push_back(make_pair(key,value));
            mp[key] = prev(lst.end());
            if (lst.size() > capacity_) {
                mp.erase(lst.begin()->first);
                lst.erase(lst.begin());
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

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
