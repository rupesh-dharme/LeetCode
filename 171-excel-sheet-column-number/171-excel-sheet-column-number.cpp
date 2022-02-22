class Solution {
public:
    int titleToNumber(string titles) {
        int result = 0;
        for (int i = 0; i < titles.size(); i++) {
            result *= 26;
            result += titles[i]-64;
        }
        return result;
    }
};