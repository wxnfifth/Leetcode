class Solution {
private:
    vector<string> ans;
    void backtrace(string word, int pos, string cur, int count) {
        if (pos == word.length()) {
            if (count > 0) {
                cur += to_string(count);
            }
            ans.push_back(cur);
        } else {
          backtrace(word, pos + 1, cur, count + 1);
          if (count > 0) {
              cur += to_string(count);
          }
          cur += word[pos];
          backtrace(word, pos + 1, cur, 0);
        } 
    }
    
public:
    vector<string> generateAbbreviations(string word) {
        backtrace(word, 0, "", 0);
        return ans;
    }
    
};