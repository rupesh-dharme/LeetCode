class Solution {
private:
    vector<vector<int>> dp;
public:
    Solution() : dp(2001, vector<int> (2001, -1)) {}
    int minCut(string s) {
        int result = recurse(s, 0, s.size()-1);
        return result;
    }
    int recurse(string &s, int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (palindrome(s, i, j)) return 0;
        int ans = INT_MAX;
        int left, right;
        for (int k = i; k < j; k++) {
            if (palindrome(s, i, k)) {
                if (dp[i][k] != -1) left = dp[i][k];
                else left = dp[i][k] = recurse(s, i, k);
                if (dp[k+1][j] != -1) right = dp[k+1][j];
                else right = dp[k+1][j] = recurse(s, k+1, j);
                ans = min(ans, 1 + left + right);
            }
            
        }
        return dp[i][j] = ans;
    }
    bool palindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};