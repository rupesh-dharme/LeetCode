class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0), col(n, 0);
        for (auto& index : indices) {
            row[index[0]]++;
            col[index[1]]++;
        }
        int odd = 0;
        for (auto& r : row) {
            for (auto& c : col) {
                if ((r + c)%2) odd ++;
            }
        }
        return odd;
    }
};