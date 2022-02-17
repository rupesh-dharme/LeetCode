class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m*n-1, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (matrix[mid/n][mid%n] == target) return true;
            else if (matrix[mid/n][mid%n] < target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         int i = 0;
//         for (; i < m; i++) {
//             if (matrix[i][0] > target) break;
//         }
//         if (i > 0) i -= 1;
//         return binary_search(matrix[i].begin(), matrix[i].end(), target);
//     }
// };