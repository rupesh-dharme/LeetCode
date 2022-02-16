class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size(), p, ri, ci;
        if (m*n != r*c) return mat;
        vector<vector<int>> answer(r, vector<int> (c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                p = (i*c) + j;
                ri = p/n;
                ci = p%n;
                answer[i][j] = mat[ri][ci];
            }
        }
        return answer;
    }
};