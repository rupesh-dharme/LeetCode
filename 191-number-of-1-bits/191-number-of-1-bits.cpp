class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res++;
            n = n & (n-1);
        }
        return res;
    }
};

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int ans = 0;
//         while (n) {
//             n = n & (n-1);
//             ans++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         return __builtin_popcount(n);
//     }
// };