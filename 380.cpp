class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            nums.push_back(val);
            mp[val] = nums.size() - 1;
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) != mp.end()) {
            int pos = mp[val];
            swap(nums[pos], nums[nums.size() - 1]);
            mp[nums[pos]] = pos;
            mp.erase(val);
            nums.pop_back();
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> mp;
};