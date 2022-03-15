class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) return mat;
        vector<vector<int>> answer(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int idx = i * c + j;
                answer[i][j] = mat[idx/n][idx%n];
            }
        }
        return answer;
    }
};

// class Solution {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
//         int m = mat.size(), n = mat[0].size(), p, ri, ci;
//         if (m*n != r*c) return mat;
//         vector<vector<int>> answer(r, vector<int> (c, 0));
//         for (int i = 0; i < r; i++) {
//             for (int j = 0; j < c; j++) {
//                 p = (i*c) + j;
//                 ri = p/n;
//                 ci = p%n;
//                 answer[i][j] = mat[ri][ci];
//             }
//         }
//         return answer;
//     }
// };