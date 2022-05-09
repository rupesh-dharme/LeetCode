class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int &lhs, int &rhs) {
            if (__builtin_popcount(lhs) < __builtin_popcount(rhs)) return true;
            else if (__builtin_popcount(lhs) == __builtin_popcount(rhs) && lhs < rhs) return true;
            return false;
        });
        return arr;
    }
};