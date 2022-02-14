class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0;
        for (; i < m; i++) {
            if (matrix[i][0] > target) break;
        }
        if (i > 0) i -= 1;
        return binary_search(matrix[i].begin(), matrix[i].end(), target);
    }
};