class Solution {
public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int max_area = 0;
//         for(int i = 0; i < grid.size(); i++)
//             for(int j = 0; j < grid[0].size(); j++)
//                 if(grid[i][j] == 1)max_area = max(max_area, AreaOfIsland(grid, i, j));
//         return max_area;
//     }
    
//     int AreaOfIsland(vector<vector<int>>& grid, int i, int j){
//         if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
//             grid[i][j] = 0;
//             return 1 + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
//         }
//         return 0;
//     }
    
    
    
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size(), mx = 0;
        
//         for (int r = 0; r < m; r++) {
//             for (int c = 0; c < n; c++) {
//                 if (grid[r][c] == 1) {
//                     mx = max(mx, area(grid, r, c, m, n));
//                 }
//             }
//         }
//         return mx;
//     }
    
//     int area(vector<vector<int>>& grid, int r, int c, int m, int n) {
//         int x[] = {0, 0, 1, -1};
//         int y[] = {1, -1, 0, 0};
//         int a = 0;
//         grid[r][c] = 0;
//         for (int i = 0; i < 4; i++) {
//             if (r + x[i] >=0 && r + x[i] < m && c + y[i] >=0 && c + y[i] < n && grid[r + x[i]][c + y[i]] == 1) {
//                 a += area(grid, r + x[i], c + y[i], m, n); 
//             }
//         }
//         return a + 1;
//     }
    

    int area(vector<vector<int>> &grid, int r, int c) {
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
            if (grid[r][c] == 0) return 0;
            grid[r][c] = 0;
            int result = 1;
            int DIR[] = {0, 1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                result += area(grid, r + DIR[i], c + DIR[i+1]);
            }
            return result;
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, area(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};