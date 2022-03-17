class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        for (char &ch : s) {
            if (ch == '(') {
                stack.push(-1);
            } else {
                if (stack.top() == -1){
                    stack.pop();
                    stack.push(1);
                } else {
                    int val = 0;
                    while (stack.top() != -1) {
                        val += stack.top();
                        stack.pop();
                    }
                    stack.pop();
                    stack.push(2*val);
                }
            }
        }
        int val = 0;
        while (stack.size()) {
            val += stack.top(); 
            stack.pop();
        }
        return val;
    }
};