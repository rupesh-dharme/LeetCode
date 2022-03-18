class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isDividing(i)) result.push_back(i);
        }
        return result;
    }
    bool isDividing(int n) {
        for (auto ch : to_string(n)) {
            if (ch == '0') return false;
            if (n % (ch - '0')) {
                return false;
            }
        }
        return true;
    }
};