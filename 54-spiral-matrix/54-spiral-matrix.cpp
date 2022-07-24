class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int up = 0, right = mat[0].size() - 1;
        int left = 0, down = mat.size() - 1;
        int n = mat.size(), m = mat[0].size();
        vector<int> result;
        
        while (result.size() < n * m) {
            for (int i = left; i <= right && result.size() < n * m; i++)
                result.push_back(mat[up][i]);
            for (int i = up + 1; i <= down && result.size() < n * m; i++)
                result.push_back(mat[i][right]);
            for (int i = right - 1; i >= left && result.size() < n * m; i--)
                result.push_back(mat[down][i]);
            for (int i = down - 1; i >= up + 1 && result.size() < n * m; i--)
                result.push_back(mat[i][left]);
            up++; down--; left++; right--;
        }
        return result;
    }
};