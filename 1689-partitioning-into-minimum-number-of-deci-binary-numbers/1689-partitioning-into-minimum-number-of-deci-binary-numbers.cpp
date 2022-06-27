class Solution {
public:
    int minPartitions(string n) {
        char mx = '0';
        for (auto ch : n) {
            if (ch >= mx) mx = ch;
        }
        return mx - '0';
    }
};