class Solution {
public:
    void mkZero(vector<vector<char>>& grid, int r, int c){
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1') {
            int DIR[] = {0, 1, 0, -1, 0};
            grid[r][c] = '0';
            for (int i = 0; i < 4; i++) {
                mkZero(grid, r+DIR[i], c+DIR[i+1]);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0, m = grid.size(), n = grid[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    mkZero(grid, r, c);
                }
            }
        }
        return islands;
    }
};