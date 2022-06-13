class Solution {
public:
    long long appealSum(string s) {
        long long prev[26] = {}, n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            res += (i + 1 - prev[s[i] - 'a']) * (n - i);
            prev[s[i] - 'a'] = i + 1;
        }
        return res;
    }
};