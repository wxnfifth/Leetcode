2 clever solution

class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for (auto a : s2) {
            if (start >= a.second || end <= a.first) continue;
            else return false;
        }
        for (auto a : s1) {
            if (start >= a.second || end <= a.first) continue;
            else s2.insert({max(start, a.first), min(end, a.second)});
        }
        s1.insert({start, end});
        return true;
    }

private:
    set<pair<int, int>> s1, s2;
};

class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        ++freq[start];
        --freq[end];
        int cnt = 0;
        for (auto f : freq) {
            cnt += f.second;
            if (cnt == 3) {
                --freq[start];
                ++freq[end];
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> freq;
};


