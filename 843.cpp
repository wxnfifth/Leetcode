/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    void findMatch(const vector<string>& wordlist, vector<vector<int>>& match, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                int cnt = 0;
                for (int t = 0; t < 6; ++t) {
                    if (wordlist[i][t] == wordlist[j][t]) {
                        cnt++;
                    }
                }
                match[i][j] = match[j][i] = cnt;
            }
        }
    }
    
    int findCandidate(const vector<int>& word_ids, const vector<vector<int>>& match) {
        int candidate = 0;
        int min_max = INT_MAX;
        for (int i : word_ids) {
            vector<int> count(7, 0);
            for (int j: word_ids) {
                count[match[i][j]]++;
            }
            int tmp_max = 0;
            for (int s = 0; s < 7; ++s) {
                tmp_max = max(tmp_max, count[s]);
            }
            if (tmp_max < min_max) {
                min_max = tmp_max;
                candidate = i;
            }
        }
        return candidate;
    }
    
    
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        //heuristic minmax
        //for each guess, make the min max match
        int n = wordlist.size();
        vector<vector<int>> match(n, vector<int>(n, 0));
        findMatch(wordlist, match, n);
        vector<int> word_ids;//candidates may contain secret
        for (int i = 0; i < n; ++i) {
            word_ids.push_back(i);
        }
        while (true) {
            int candidate = findCandidate(word_ids, match);
            int ans = master.guess(wordlist[candidate]);
            if (ans == 6) {
                break;
            }
            vector<int> next_word_ids;
            for (int i: word_ids) {
                if (match[candidate][i] == ans && i != candidate) {
                    next_word_ids.push_back(i);
                }
            }
            word_ids = next_word_ids;
        } 
    }
};
