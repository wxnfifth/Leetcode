class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector< pair<double,int> > ratio(n);
        for (int i = 0; i < n; ++i) {
            ratio[i] = make_pair((double)wage[i] / (double)quality[i], i);
        }
        sort(ratio.begin(), ratio.end(), [](pair<double,int> a, pair<double,int> b) {
           return a.first < b.first; 
        });
        
        //top k with smallest ratio
        priority_queue<int> que;//max (k - 1) quality
        double quality_sum = 0;
        for (int i = 0; i < K - 1; ++i) {
            que.push(quality[ratio[i].second]);
            quality_sum += quality[ratio[i].second];
        }
        double ans = 1e100;
        for (int i = K - 1; i < n; ++i) {
            //top K element in mp is smallest 
            quality_sum += quality[ratio[i].second];
            double wage = quality_sum * ratio[i].first;
            ans = min(ans, wage);
            que.push(quality[ratio[i].second]);
            quality_sum -= que.top();
            que.pop();
        }
        return ans;
    }
};
