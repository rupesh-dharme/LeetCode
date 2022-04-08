class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        recurse(grid, m-1, n-1, count);
        return count;
    }
    void recurse(vector<vector<int>> &grid, int i, int j, int &count) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) {
            if (grid[i][j] < 0) {
                grid[i][j] = INT_MAX;
                count++;
                int DIR[] = {0, -1, 0};
                for (int k = 0; k < 2; k++) {
                    recurse(grid, i + DIR[k], j + DIR[k+1], count);
                }
            }
        }
    }
};