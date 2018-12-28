class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> address;
        for (string s:emails) {
            string key;
            int status = 0; // 0 is in local name and no '+'
                            // 1 is in local name and after '+'
                            // 2 is in domain name
            for (int i = 0; i < s.length(); ++i) {
                if (status == 0 && s[i] == '+') {
                    status = 1;
                } else if (status < 2 && s[i] == '@') {
                    status = 2;
                } 
                if ((status == 0 && s[i] != '.') || status == 2) {
                    key += s[i];
                } 
            }
            address.insert(key);
        }
        return address.size();
    }
};
