class Solution {
public:
    // int gcd(int a, int b) {
    //     if (a == 0) return b;
    //     return gcd(b%a, a);
    // }
    int findGCD(vector<int>& nums) {
        int mx = INT_MIN, mn = INT_MAX;
        for (auto &num : nums) {
            if (num < mn) mn = num;
            if (num > mx) mx = num;
        }
        return __gcd(mn, mx);
    }
};