// class Solution {
// private:
//     unordered_map<char, char> mp = {{']', '['}, {')', '('}, {'}', '{'}};
// public:
//     bool isValid(string s) {
//         // stack<char> stack;
//         int top = -1;
        
//         for (int i = 0; i < s.size(); i++) {
//             char ch = s[i];
//             if (ch == '(' || ch == '[' || ch == '{') top = i;
//             else {
//                 if (top == -1 || s[top] != mp[ch]) return false;
//                 else {
//                     top = getTop(i-1, s);
//                 }
//             }
//         }
//         return top == -1;
//     }
//     int getTop(int i, string &s) {
//         int right = 0;
//         while (i >= 0) {
//             if (mp.find(s[i]) != mp.end()) right++;
//             else right--;
            
//             if (right < 0) return i;
            
//             i--;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mp = {{']', '['}, {')', '('}, {'}', '{'}};
        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') stack.push(ch);
            else {
                if (stack.size() && stack.top() == mp[ch]) stack.pop();
                else return false;
            }
        }
        return stack.empty();
    }
};

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> stk;
//         for (auto& ch : s) {
//             if (ch == '(' || ch == '{' || ch == '[') {
//                 stk.push(ch);
//             }
//             else {
//                 if (stk.empty()) return false;
//                 if (ch == stk.top() + 1 || ch == stk.top() + 2) {
//                     stk.pop();
//                 } else return false;
//             }
//         }
//         return stk.empty();
//     }
// };