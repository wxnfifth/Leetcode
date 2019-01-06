class Solution {
    
public:
    int lengthLongestPath(string input) {
        //use stack to find longest path
        int ans = 0;
        stack<pair<int,int>> path;//first is string length, second is num of tabs
        int stack_total_length = 0;
        int pos = 0;
        while (pos < input.length()) {
            int s_length = 0;
            int count_tab = 0;
            bool is_file = false;
            while (pos < input.length() && input[pos] != '\n') {
                if (input[pos] == '\t') {
                    count_tab++;
                } else {
                    s_length++;
                    if (input[pos] == '.') {
                        is_file = true;
                    }
                }
                pos++;
            }
            if (!is_file) {
                s_length++;//add '/' in path
            }
            //pos at '\n' or end
            pos++;
            //pos points to next valid directory
            while (!path.empty() && path.top().second >= count_tab) {
                stack_total_length -= path.top().first;
                path.pop();
            }
            if (is_file) {
                ans = max(ans, stack_total_length + s_length);
            } else {
                path.push(make_pair(s_length, count_tab));
                stack_total_length += s_length;
            }
        }
        return ans;
    }
};
