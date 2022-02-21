class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g, int steps = 0) {
      queue<pair<int, int>> q;
      q.push({ 0, 0 });
      while (!q.empty()) {
        ++steps;
        queue<pair<int, int>> q1;
        while (!q.empty()) {
          auto c = q.front();
          q.pop();
          if (c.first >= 0 && c.second >= 0 && c.first < g.size() && c.second < g.size() && !g[c.first][c.second]) {
            g[c.first][c.second] = 1;
            if (c.first == g.size() - 1 && c.second == g.size() - 1) return steps;
            for (auto i = -1; i < 2; ++i)
              for (auto j = -1; j < 2; ++j)
                if (i != 0 || j != 0) q1.push({ c.first + i, c.second + j });
          }
        }
        swap(q, q1);
      }
      return -1;
}
};

// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int path = 0, m = grid.size();
//         queue<pair<int, int>> q;
//         if (grid[0][0] == 1) return -1;
//         q.push({0, 0});
//         while(!q.empty()) {
//             path++;
//             // if (path > 2*m+1) return -1;
//             int n = q.size();
//             for (int i = 0; i < n; i++) {
//                 auto [r, c] = q.front();
//                 grid[r][c] = 1;
//                 q.pop();
//                 if (r == m-1 && c == m-1) return path;
//                 int rs[] = {-1, 0, 1, 0, 1, 1, -1, -1};
//                 int cs[] = {0, -1, 0, 1, 1, -1, 1, -1};
//                 for (int j = 0; j < 8; j++) {
//                     if (0 <= r+rs[j] && r+rs[j]<m && 0 <= c+cs[j] && c+cs[j]<m && grid[r+rs[j]][c+cs[j]]!=1) {
//                         q.push({r+rs[j], c+cs[j]});
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };