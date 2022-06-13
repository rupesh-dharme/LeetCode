class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        int ans = minPathSum(triangle, 0, 0, dp);
        return ans;
    }
    int minPathSum(vector<vector<int>>& triangle, int r, int c, vector<vector<int>>& dp) {
        if (r == triangle.size()) return 0;
        if (dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = triangle[r][c] + min(minPathSum(triangle, r+1, c, dp), minPathSum(triangle, r+1, c+1, dp));
    }
};