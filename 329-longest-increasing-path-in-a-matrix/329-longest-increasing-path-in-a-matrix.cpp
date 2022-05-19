class Solution {
private:
    vector<vector<int>> dp;
    int m, n;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int> (n, -1));
        int ans = 0;    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(matrix, i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>> &matrix, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        int res = 1;
        int DIR[] = {0, 1, 0, -1, 0};
        for (int d = 0; d < 4; d++) {
            int x = i + DIR[d], y = j + DIR[d+1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                res = max(res, 1 + dfs(matrix, x, y));
            }
        }
        return dp[i][j] = res;
    }
};