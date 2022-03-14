class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int mn = min(rowSum[r], colSum[c]);
                rowSum[r] -= mn; colSum[c] -= mn;
                result[r][c] = mn;
            }
        }
        return result;
    }
};