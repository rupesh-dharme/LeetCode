class Solution {
public:
    void mkZero(vector<vector<int>> & grid, int r) {
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[r][i] == 1) {
                grid[r][i] = 0;
                mkZero(grid, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), provinces = 0;
        for (int r = 0; r < m; r++) {
            bool added = false;
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    if (!added) {provinces++; added = true;}
                    if (r != c) mkZero(grid, c);
                }
            }
        }
        return provinces;
    }
};