class Solution {
    
    int findKthLargest(int k, vector<int> a, vector<int> b) {
        int m = a.size();
        int n = b.size();
        if (m > n) {
            return findKthLargest(k, b, a);
        }
        if (m == 0) {
            return b[k - 1];
        }
        if (k == 1) {
            return min(a[0], b[0]);
        }
        // compare 
        int pos_a = min(k / 2, m);
        int pos_b = k - pos_a;
        if (a[pos_a - 1] < b[pos_b - 1]) {
            return findKthLargest(k - pos_a, vector<int>(a.begin() + pos_a, a.end()), b); 
        } else if (a[pos_a - 1] > b[pos_b - 1]) {
            return findKthLargest(k - pos_b, a, vector<int>(b.begin() + pos_b, b.end()));
        } else {
            return a[pos_a - 1];    
        }
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //define a find kth largest element in median sorted array
        int m = nums1.size();
        int n = nums2.size();
        if ((m + n) % 2 == 0) {//total is 4, find 2th and 3th element
            return (findKthLargest((m + n) / 2, nums1, nums2) + 
                    findKthLargest((m + n) / 2 + 1, nums1, nums2)) / 2.0;
        } else {//total is 3, find 2th element
            return findKthLargest((m + n) / 2 + 1, nums1, nums2);
        }
    }
};
