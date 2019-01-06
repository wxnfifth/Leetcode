class RLEIterator {
    int pos = 0;
    int count = 0;
    vector<int> v;
public:
    RLEIterator(vector<int> A) {
        v = A;
    }
    
    int next(int n) {
        while (n > 0) {
            if (pos >= v.size()) {
                return -1;
            } else if (count + n <= v[pos]) {
                int ans = v[pos + 1];
                count += n;
                if (count == v[pos]) {
                    pos += 2;
                    count = 0;
                }
                return ans;
            } else {
                n -= (v[pos] - count);
                count = 0;
                pos += 2;
            }
        }
        //should not here
        return -1;
    }
};
