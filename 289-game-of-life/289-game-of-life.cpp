class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> temp(m, vector<int> (n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
                int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    cnt += alive(i + dx[k], j + dy[k], board);
                }
                if (board[i][j] == 0 && cnt == 3) temp[i][j] = 1;
                else if (board[i][j] == 1 && cnt < 2) temp[i][j] = 0;
                else if (board[i][j] == 1 && cnt >= 2 && cnt <= 3) temp[i][j] = 1;
                else if (board[i][j] == 1 && cnt > 3) temp[i][j] = 0;
                else temp[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = temp[i][j];
            }
        }
    }
    int alive(int r, int c, vector<vector<int>> &board) {
        if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size()) {
            if (board[r][c] == 1) return 1;
        }
        return 0;
    }
};