class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        stack.push(-1);
        int mx = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') stack.push(i);
            else {
                stack.pop();
                if (stack.size()) {
                    mx = max(mx, i - stack.top());
                }
                else stack.push(i);
            }
        }
        return mx;
    }
};