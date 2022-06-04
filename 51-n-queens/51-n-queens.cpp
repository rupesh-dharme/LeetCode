class Solution {
private:
    vector<vector<string>> res;
    vector<string> board;
public:
    bool isSafe(int row, int col, int n) {
        int r = row, c = col;
        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }
        c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }
        r = row; c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++; c--;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string> (n, string (n, '.'));
        solve(n);
        return res;
    }
    void solve(int n, int col = 0) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n)) {
                board[row][col] = 'Q';
                solve(n, col + 1);
                board[row][col] = '.';
            }
        }
    }
};