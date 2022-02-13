class Solution {
public:
    uint32_t reverseBits(uint32_t n) { // 11111111111111111111111111111101
        bitset<32> b(n); 
        string s = b.to_string();
        reverse(s.begin(), s.end()); // 10111111111111111111111111111111
        return s[0]=='0' ? stoi(s, 0, 2) : (2147483648 + stoi(s.substr(1, s.size()-1), 0, 2)); // check because of unsigned integer.
    }
};