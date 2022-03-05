class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == word[0]) {
                    bool temp = recurse(board, r, c, word, 0);
                    if (temp) return true;
                }
            }
        }
        return false;
    }
    bool recurse(vector<vector<char>>& board, int r, int c, string& word, int k) {
        if (k == word.size()) return true;
        if (r >= 0 && c >= 0 && r < board.size() && c < board[0].size()) {
            if (board[r][c] != word[k]) return false;
            int DIR[] = {0, 1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                char temp = board[r][c];
                board[r][c] = '0';
                int x = r + DIR[i];
                int y = c + DIR[i+1];
                if (recurse(board, x, y, word, k+1)) return true;
                board[r][c] = temp;
            }
        }
        return false;
    }
};