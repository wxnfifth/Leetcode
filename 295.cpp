//very slow, maybe C++'s priority_queue is slow
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    
    // Adds a number into the data structure.
    //if even, left.size == right.size
    //if odd, left.size == right.size + 1
    void addNum(int num) {
        if (left.empty() || left.top() >= num) {
            left.push(num);
        } else {
            right.push(num);
        }
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (left.size() == right.size()) {
            return ((double)left.top() + (double)right.top()) / 2.0;
        } else {
            return (double)left.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();