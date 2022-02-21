class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                s.push(str[i]);
            }
            else {
                if (s.size() && (str[i]-1 == s.top() || str[i]-2 == s.top())) s.pop();
                else return false;
            }
        }
        if (s.size()) return false;
        return true;
    }
};