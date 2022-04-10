class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> temp(row+1,vector<int>(col+1,0));
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                temp[i][j] = temp[i-1][j] + temp[i][j-1] - temp[i-1][j-1];
                temp[i][j] += mat[i-1][j-1];
            }
        }

        vector<vector<int>> ans = mat;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int x = max(0,i-k);
                int y = max(0,j-k);
                int c = min(row,i+k+1);
                int d = min(col,j+k+1);
                ans[i][j] = temp[c][d] - temp[c][y] - temp[x][d] + temp[x][y];
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
//         int m = mat.size(), n = mat[0].size();
//         vector<vector<int>> sum(m, vector<int> (n, 0));
//         sum[0][0] = mat[0][0];
//         for (int r = 1; r < m; r++) sum[r][0] += mat[r][0] + sum[r-1][0];
//         for (int c = 1; c < n; c++) sum[0][c] += mat[0][c] + sum[0][c-1];
//         for (int r = 1; r < m; r++) {
//             for (int c = 1; c < n; c++) {
//                 sum[r][c] += (sum[r-1][c] + sum[r][c-1] - sum[r-1][c-1]);
//             }
//         }
//         vector<vector<int>> res(m, vector<int> (n, 0));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 int rtop, rbottom, cleft, cright;
//                 rtop = r-k >= 0 ? r-k : 0;
//                 rbottom = r+k < m ? r+k : m-1;
//                 cleft = c-k >= 0 ? c-k : 0;
//                 cright = c+k < n ? c-k : n-1;
//                 // res[i][j] = 
//             }
//         }
//         return res;
//     }
// };