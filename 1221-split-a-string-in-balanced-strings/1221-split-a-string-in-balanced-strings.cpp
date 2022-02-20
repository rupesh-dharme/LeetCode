class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size(), l, r, c, cnt;
        l = r = c = cnt = 0;
        while (r < n) {
            if (!(c += s[r++]=='L' ? -1 : 1)) { cnt++; l = r;}
        }
        return cnt;
    }
};