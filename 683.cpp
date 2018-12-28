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
