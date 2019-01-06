class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        //store length of string in first few digits
        string ans;
        for (string& s: strs) {
            ans += to_string(s.length()) + "#" + s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.length()) {
            int num = 0;
            while (i < s.length() && s[i] != '#') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i++;//now point to next of #
            ans.push_back(s.substr(i, num));
            i += num;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
