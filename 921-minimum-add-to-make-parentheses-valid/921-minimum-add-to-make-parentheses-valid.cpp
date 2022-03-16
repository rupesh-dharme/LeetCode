class Solution {
public:
    int minAddToMakeValid(string s) {                                                                   int open = 0, close = 0, count = 0;
        for (auto &ch : s) {
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                if (count > 0) {
                    count--;
                } else {
                    close++;
                }
            }
        }
        return close + count;
    }
};