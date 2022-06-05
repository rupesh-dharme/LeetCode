class Solution {
private:
    int count = 0;
    vector<vector<int>> board;
public:
    int totalNQueens(int n) {
        board = vector<vector<int>> (n, vector<int> (n, 0));
        return solve(n);
    }
    
    int solve(int n, int col = 0) {
        if (col == n) {
            return 1;
        }
        int res = 0;
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n)) {
                board[row][col] = 1;
                res += solve(n, col + 1);
                board[row][col] = 0;
            }
        }
        return res;
    }
    
    bool isSafe(int row, int col, int n) {
        int r = row, c = col;
        while (c >= 0) if (board[r][c--] == 1) return false;
        c = col;
        while (r >= 0 && c >= 0) if (board[r--][c--] == 1) return false;
        r = row;
        c = col;
        while (r < n && c >= 0) if (board[r++][c--] == 1) return false;
        return true;
    }
};