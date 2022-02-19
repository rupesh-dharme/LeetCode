class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rows(n, 0), cols(n, 0);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                rows[r] = max(rows[r], grid[r][c]);
                cols[c] = max(cols[c], grid[r][c]);
            }
        }
        int diff = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] < min(rows[r], cols[c])) {
                    diff += min(rows[r], cols[c]) - grid[r][c];
                }
            }
        }
        return diff;
    }
};