class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> extra(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 or j == 0) {
                    extra[i][j] = matrix[i][j];
                    continue;
                }
                if (matrix[i][j] == 1) extra[i][j] = min(min(extra[i][j-1], extra[i-1][j]), extra[i-1][j-1]) + 1;
                else extra[i][j] = 0;
            }
        }
        int result = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) result += extra[i][j];
        return result;
    }
};