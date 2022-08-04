class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / __gcd(p, q);
        if ((lcm / p) % 2 == 0) return 0;
        if ((lcm / q) % 2 == 0) return 2;
        return 1;
    }
};