class Solution {
    int gasNeeded(double dis, vector<int>& stations) {
        int count = 0;
        for (int i = 1; i < stations.size(); ++i) {
            count += (int)((double)(stations[i] - stations[i - 1]) / dis); 
        }
        return count;
    }
    
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        //binary search to find the candidate distance, for each distance, check the more gas stations needed <= K 
        double left = 0;
        double right = 1e8;
        while ( left + 1e-6 < right) {
            double mid = (left + right) / 2;
            int number = gasNeeded(mid, stations);
            if (number <= K) {
                right = mid;
            } else{
                left = mid;
            }
        }
        return left;
    }
};
