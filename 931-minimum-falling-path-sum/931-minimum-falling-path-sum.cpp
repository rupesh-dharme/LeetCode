class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int l = j > 0 ? matrix[i-1][j-1] : INT_MAX;
                int m = matrix[i-1][j];
                int r = j < n-1 ? matrix[i-1][j+1] : INT_MAX;
                matrix[i][j] += min({l, m, r});
            }
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};