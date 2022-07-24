class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        int n = grid.size(), m = grid[0].size();
        int i = 0, j = m - 1;
        while (i < n and j >= 0) {
            if (grid[i][j] == target) return true;
            else if (grid[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};