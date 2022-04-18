class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};

// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int distance = 0;
//         // while (x && y) {
//         //     if ((x & 1) ^ (y & 1)) distance++;
//         //     x >> 1;
//         //     y >> 1;
//         // }
//         int num = x ^ y;
//         return __builtin_popcount(num);
//         // return distance;
//     }
// };