class Solution {

int compute(int a, int b, string op) {
    if (op == "+") {
        return a + b;    
    } else if (op == "-") {
        return a - b;
    } else if (op == "/") {
        return a / b;
    } else if (op == "*") {
        return a * b;
    }
    return 0;
}
    
    
public:
    int evalRPN(vector<string>& tokens) {
        //stack of number and
        //stack of operator
        stack<int> stk_num;
        for (int i = 0; i < tokens.size(); ++i) {
            if ((tokens[i][0] >= '0' && tokens[i][0] <= '9') ||
                (tokens[i][0] == '-' && tokens[i].length() > 1)) {
                stk_num.push(atoi(tokens[i].c_str()));
            } else {
                int b = stk_num.top();
                stk_num.pop();
                int a = stk_num.top();
                stk_num.pop();
                int c = compute(a, b, tokens[i]);
                stk_num.push(c);
            }
        }
        return stk_num.top();
    }
};
