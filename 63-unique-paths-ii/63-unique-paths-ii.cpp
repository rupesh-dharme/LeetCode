class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int i;
        for (i = 0; i < m; i++) {
            if (grid[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for (; i < m; i++) dp[i][0] = 0;
        for (i = 0; i < n; i++) {
            if (grid[0][i] == 1) break;
            dp[0][i] = 1;
        }
        for (; i < n; i++) dp[0][i] = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 1) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};