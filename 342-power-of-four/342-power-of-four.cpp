class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if ((n & (n - 1)) == 0 && (__builtin_popcount(n - 1) % 2) == 0) return true;
        return false;
    }
    // bool isPowerOfFour(int n) {
    //     if (n == 0) return false;
    //     while (n % 4 == 0) n /= 4;
    //     if (n == 1) return true;
    //     return false;
    // }
};