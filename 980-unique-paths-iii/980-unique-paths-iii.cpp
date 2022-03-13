class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0, m = grid.size(), n = grid[0].size(), zero = 0;
        int r, c;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) zero++;
                if (grid[i][j] == 1) {
                    r = i; c = j;
                }
            }
        }
        recurse(grid, r, c, count, zero);
        return count;
    }
    void recurse(vector<vector<int>>& grid, int r, int c, int& count, int zero) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == -1) return;
        if (grid[r][c] == 2) {
            if (zero == 0) count++;
            return;
        }
        int temp = grid[r][c];
        if (temp == 0) --zero;
        grid[r][c] = -1;
        int DIR[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int rn = r + DIR[i];
            int cn = c + DIR[i+1];
            recurse(grid, rn, cn, count, zero);
        }
        grid[r][c] = temp;
    }
};