class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return unique(m-1, n-1, dp);
    }
    int unique(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 || n == 0) return 1;
        if (dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = unique(m-1, n, dp) + unique(m, n-1, dp);
    }
};