class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for (auto ch : s) {
            if (stack.size()) {
                if (stack.top() == ch) {
                    stack.pop();
                    continue;
                }
            }
            stack.push(ch);
        }
        string result;
        while (stack.size()) {
            result += stack.top();
            stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};