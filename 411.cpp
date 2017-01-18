//very slow, but can work
class Solution {
public:

    //find abbreviations , and check conflict
    
    string min_abbr;
    int min_len = INT_MAX;
    
    void checkConflict(string target, string abbr, int len, const vector<string>& dictionary) {
            //cout << target << " " << len << " " << abbr << "\n";
        if (len > min_len) {
            return;
        } 
        for (auto d: dictionary) {
            if (target.length() != d.length()) {
                continue;
            }
            bool conflict = true;
            for (int i = 0, j = 0; i < abbr.length() && j < d.length();  ) {
                if (isdigit(abbr[i])) {
                    string n_str;
                    while (i < abbr.length() && isdigit(abbr[i])) {
                        n_str += abbr[i];
                        i++;
                    }
                    int n = stoi(n_str);
                    j += n;
                } else if (abbr[i] == d[j]) {
                    i++;
                    j++;
                } else if (abbr[i] != d[j]) {
                    conflict = false;
                    break;
                }
            }
            if (conflict) {
                return;
            }
        }
        min_abbr = abbr;
        min_len = len;
    }
    
    void dfs(const string& target, string abbr, int len, int pos, int cnt, const vector<string>& dictionary) {
        //cout << "xx" << abbr << "xx" << pos << "\n";
        if (pos == target.length()) {
            if (cnt > 0) {
                abbr += to_string(cnt);
                len++;
            }
            //cout << abbr << "\n";
            checkConflict(target, abbr, len, dictionary);
        } else {
            dfs(target, abbr, len, pos + 1, cnt + 1, dictionary);
            if (cnt > 0) {
                abbr += to_string(cnt);
                len++;
            }
            abbr += target[pos];
            len++;
            dfs(target, abbr, len, pos + 1, 0, dictionary);
        }
    }
    
    string minAbbreviation(string target, vector<string>& dictionary) {
        
        dfs(target, "", 0, 0, 0, dictionary);
        
        return min_abbr;
    }
};