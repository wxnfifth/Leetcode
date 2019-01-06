class MovingAverage {
    queue<int> q;
    double sum = 0;
    int size_;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        size_ = size;
    }
    
    double next(int val) {
        if (q.size() == size_) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum / q.size();
    }
};
