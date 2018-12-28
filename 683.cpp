


class Solution {

 
    int lowbit(int t)
    {
    return t&(-t);
    }
 
    int get(int x, vector<int>& sum) {
	    int ans = 0;
	    for (int i = x; i > 0;i -= lowbit(i)) {
		    ans += sum[i];
	    }
	    return ans;
    }
 
    void add(int x,int value, vector<int>& sum)
    {
        for(int i=x;i<= sum.size() - 1;i+=lowbit(i))
            sum[i]+=value;
    }
     
    
    public:
    int kEmptySlots(vector<int>& flowers, int k) {
        //simulate the day one by one
        //for each day, find two flower in status of blooming and number of flowers between is k-> sum of interval with length k + 2 == 2 , begin and end of interval is 1
        //on day i, x = flowers[i] will bloom, check x - k - 1 and x is bloom and sum[x] - sum[x - k] == 0 or x + k + 1 and x is bloom and sum[x + k] - sum[x] == 0
        int n = flowers.size();
        vector<int> garden(n + 1, 0);
        if (k + 2 > n) {
            return -1;
        }
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < flowers.size(); ++i) {
            int x = flowers[i];
            garden[x] = 1;
            add(x, 1, sum);
            //cout << "x " << x << "\n";
            //cout << "x - k - 1 " << x - k -1 << "\n";
            //cout << "garden[x - k - 1] = " << garden[x - k - 1] << "\n";
            //cout << "get(x,sum)" << get(x, sum) << "\n";
            //cout << "get(x - k, sum)" << get(x - k, sum) << "\n";
            if (x - k - 1 >= 1 && garden[x - k - 1] == 1 && (get(x - 1, sum) - get(x - k - 1, sum)) == 0) {
                return i + 1;
            }
            if (x + k + 1 <= n && garden[x + k + 1] == 1 && (get(x + k, sum) - get(x, sum) == 0)) {
                return i + 1;
            }
        }
        return -1;
        
        
    }
};

class Solution {
    public int kEmptySlots(int[] flowers, int k) {
        int[] days = new int[flowers.length];
        for (int i = 0; i < flowers.length; i++) {
            days[flowers[i] - 1] = i + 1;
        }

        MinQueue<Integer> window = new MinQueue();
        int ans = days.length;

        for (int i = 0; i < days.length; i++) {
            int day = days[i];
            window.addLast(day);
            if (k <= i && i < days.length - 1) {
                window.pollFirst();
                if (k == 0 || days[i-k] < window.min() && days[i+1] < window.min()) {
                    ans = Math.min(ans, Math.max(days[i-k], days[i+1]));
                }
            }
        }

        return ans < days.length ? ans : -1;
    }
}

class MinQueue<E extends Comparable<E>> extends ArrayDeque<E> {
    Deque<E> mins;

    public MinQueue() {
        mins = new ArrayDeque<E>();
    }

    @Override
    public void addLast(E x) {
        super.addLast(x);
        while (mins.peekLast() != null &&
                x.compareTo(mins.peekLast()) < 0) {
            mins.pollLast();
        }
        mins.addLast(x);
    }

    @Override
    public E pollFirst() {
        E x = super.pollFirst();
        if (x == mins.peekFirst()) mins.pollFirst();
        return x;
    }

    public E min() {
        return mins.peekFirst();
    }
}

Approach #1: Insert Into Sorted Structure [Accepted]
Intuition

Let's add flowers in the order they bloom. When each flower blooms, we check it's neighbors to see if they can satisfy the condition with the current flower.

Algorithm

We'll maintain active, a sorted data structure containing every flower that has currently bloomed. When we add a flower to active, we should check it's lower and higher neighbors. If some neighbor satisfies the condition, we know the condition occurred first on this day.


Complexity Analysis

Time Complexity (Java): O(N \log N)O(NlogN), where NN is the length of flowers. Every insertion and search is O(\log N)O(logN).

Time Complexity (Python): O(N^2)O(N 
2
 ). As above, except list.insert is O(N)O(N).

Space Complexity: O(N)O(N), the size of active.

Approach #2: Min Queue [Accepted]
Intuition

For each contiguous block ("window") of k positions in the flower bed, we know it satisfies the condition in the problem statement if the minimum blooming date of this window is larger than the blooming date of the left and right neighbors.

Because these windows overlap, we can calculate these minimum queries more efficiently using a sliding window structure.

Algorithm

Let days[x] = i be the time that the flower at position x blooms. For each window of k days, let's query the minimum of this window in (amortized) constant time using a MinQueue, a data structure built just for this task. If this minimum is larger than it's two neighbors, then we know this is a place where "k empty slots" occurs, and we record this candidate answer.

To operate a MinQueue, the key invariant is that mins will be an increasing list of candidate answers to the query MinQueue.min.

For example, if our queue is [1, 3, 6, 2, 4, 8], then mins will be [1, 2, 4, 8]. As we MinQueue.popleft, mins will become [2, 4, 8], then after 3 more popleft's will become [4, 8], then after 1 more popleft will become [8].

As we MinQueue.append, we should maintain this invariant. We do it by popping any elements larger than the one we are inserting. For example, if we appended 5 to [1, 3, 6, 2, 4, 8], then mins which was [1, 2, 4, 8] becomes [1, 2, 4, 5].

Note that we used a simpler variant of MinQueue that requires every inserted element to be unique to ensure correctness. Also, the operations are amortized constant time because every element will be inserted and removed exactly once from each queue.


Complexity Analysis

Time Complexity: O(N)O(N), where NN is the length of flowers. In enumerating through the O(N)O(N) outer loop, we do constant work as MinQueue.popleft and MinQueue.min operations are (amortized) constant time.

Space Complexity: O(N)O(N), the size of our window.

Approach #3: Sliding Window [Accepted]
Intuition

As in Approach #2, we have days[x] = i for the time that the flower at position x blooms. We wanted to find candidate intervals [left, right] where days[left], days[right] are the two smallest values in [days[left], days[left+1], ..., days[right]], and right - left = k + 1.

Notice that these candidate intervals cannot intersect: for example, if the candidate intervals are [left1, right1] and [left2, right2] with left1 < left2 < right1 < right2, then for the first interval to be a candidate, days[left2] > days[right1]; and for the second interval to be a candidate, days[right1] > days[left2], a contradiction.

That means whenever whether some interval can be a candidate and it fails first at i, indices j < i can't be the start of a candidate interval. This motivates a sliding window approach.

Algorithm
