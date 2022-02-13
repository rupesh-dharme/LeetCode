class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((0xffff0000 & n) >> 16) | ((0x0000ffff & n) <<16);
        n = ((0xff00ff00 & n) >> 8) | ((0x00ff00ff & n) << 8);
        n = ((0xf0f0f0f0 & n) >> 4) | ((0x0f0f0f0f & n) << 4);
        n = ((0xcccccccc & n) >> 2) | ((0x33333333 & n) << 2);
        n = ((0xaaaaaaaa & n) >> 1) | ((0x55555555 & n) << 1);
        return n;
    }
};


// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         bitset <32> b(n);
//         string s = b.to_string();
//         reverse(s.begin(), s.end());
//         bitset <32> b2(s);
//         return b2.to_ulong();
//     }
// };


// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) { // 11111111111111111111111111111101
//         bitset<32> b(n); 
//         string s = b.to_string();
//         reverse(s.begin(), s.end()); // 10111111111111111111111111111111
//         return s[0]=='0' ? stoi(s, 0, 2) : (2147483648 + stoi(s.substr(1, s.size()-1), 0, 2)); // check because of unsigned integer.
//     }
// };