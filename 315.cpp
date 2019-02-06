class Solution {
    void mergeSort(vector<int>& ans, vector<pair<int,int>>& v, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(ans, v, start, mid);
        mergeSort(ans, v, mid + 1, end);
        //for each number on left part
        //how many number on right part and is smaller 
        int i = start;
        int j = mid + 1;
        vector<pair<int,int>> tmp;
        while (i <= mid || j <= end) {
            if (j > end || (i <= mid && v[i].first <= v[j].first)) {
                tmp.push_back(v[i]);
                ans[v[i].second] += j - (mid + 1);
                i++;
            } else {
                tmp.push_back(v[j]);
                j++;
            }
        }
        for (int i = start; i <= end; ++i) {
            v[i] = tmp[i - start];
        }
    }
    
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        //merge sort to solve
        vector<int> ans(nums.size(), 0);
        vector<pair<int,int>> v;
        for (int i = 0; i < nums.size(); ++i) {
            v.push_back(make_pair(nums[i], i));
        }
        mergeSort(ans, v, 0, nums.size() - 1);
        return ans;
    }
};
