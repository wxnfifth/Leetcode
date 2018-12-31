class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string t = A;
        int cnt = 1;
        while (t.length() < B.length()) {
            t += A;
            cnt++;
        }
        //repeat until longer than B
        if (t.find(B) != string::npos) {
            return cnt; 
        }
        //if still cannot, maybe A is abcd B is dabcdabcda, abcdabcdabcd cannot, but one more repeat will solve this situation
        t += A;
        cnt++;
        if (t.find(B) != string::npos) {
            return cnt; 
        }
        return -1;
    }
};

https://leetcode.com/articles/repeated-string-match/

