class Solution {
public:
    int countGoodSubstrings(string s) {
        int l = 0, r = 2, n = s.size(), count = 0, m;
        if (n < 3) return 0;
        while (r < n) {
            m = (l+r)/2;
            if (s[l]!=s[m] && s[m]!=s[r] && s[r]!=s[l]) count++;
            r++;l++;
        }
        return count;
    }
};