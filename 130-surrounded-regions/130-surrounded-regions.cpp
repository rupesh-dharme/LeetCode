class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<char>> temp(m, vector<char>(n, 'X'));
        for (int r = 0; r < m; r++) {
            if (r == 0 || r == m-1) {
                for (int j = 0; j < n; j++) {
                    dfs(board, r, j, m, n, temp);
                }
            }
            else {
                dfs(board, r, 0, m, n, temp);
                dfs(board, r, n-1, m, n, temp);
            }
        }
        board = temp;
    }
    void dfs(vector<vector<char>>& board, int r, int c, int m, int n, vector<vector<char>>& temp) {
        if (r >= m || r < 0 || c >= n || c < 0 || board[r][c] == 'X') return;
        int DIR[] = {0, 1, 0, -1, 0};
        board[r][c] = 'X';
        temp[r][c] = 'O';
        for (int i = 0; i < 4; i++) {
            int rr = r + DIR[i];
            int cc = c + DIR[i+1];
            dfs(board, rr, cc, m, n, temp);
        }
    }
};