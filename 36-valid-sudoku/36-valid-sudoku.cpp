class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> rows(10, vector<char>(10, '0'));
        vector<vector<char>> cols(10, vector<char>(10, '0'));
        vector<vector<char>> grids(10, vector<char>(10, '0'));
        for (int i = 0; i < 81; i++) {
            int row = i/9;
            int col = i%9;
            int grid = 3*(row/3) + (col/3);
            if (board[row][col] == '.') continue;
            int num = board[row][col] - 48;
            if (rows[row][num] == '0' && cols[col][num] == '0' && grids[grid][num] == '0') {
                rows[row][num] = cols[col][num] = grids[grid][num] = board[row][col];
            }
            else {
                return false;
            }
        }
        return true;
    }
};