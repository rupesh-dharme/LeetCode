class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        string ans;
        for (int i = 0; i < n; i++) {
            if (number[i] == digit) {
                string num = number.substr(0, i) + number.substr(i+1);
                if (num > ans) ans = num;
            }
        }
        return ans;
    }
};