class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[26] = {0}, res = 1;
        for (auto ch : s) {
            int idx = ch - 'a';
            dp[idx] += 1;
            for(int i = max(0, idx - k); i <= min (25, idx + k); i++) {
                if (i != idx) {
                    dp[idx] = max(dp[idx], dp[i] + 1);
                    
                }
                res = max(res, dp[idx]);
            }
        }
        return res;
    }
};