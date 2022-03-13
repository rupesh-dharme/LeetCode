class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto& ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            }
            else {
                if (stk.empty()) return false;
                if (ch == stk.top() + 1 || ch == stk.top() + 2) {
                    stk.pop();
                } else return false;
            }
        }
        return stk.empty();
    }
};