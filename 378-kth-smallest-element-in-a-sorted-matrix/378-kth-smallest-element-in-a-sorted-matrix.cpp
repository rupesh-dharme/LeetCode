// class Compare {
// public:
//     static vector<vector<int>> &mat;
//     // Compare(vector<vector<int>> &matrix) : mat(matrix) {}
//     bool operator() (pair<int, int> &a, pair<int, int> &b) {
//         return mat[a.first][a.second] > mat[b.first][b.second];
//     }
// };

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_set<string> vis;
        auto compare = [&matrix] (pair<int, int> &a, pair<int, int> &b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        pq.push({0, 0});
        while (pq.size()) {
            int sz = pq.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y] = pq.top(); pq.pop();
                k--;
                if (k == 0) return matrix[x][y];
                if (x + 1 < n && !vis.count(to_string(x + 1) + ' ' + to_string(y))) {
                    pq.push({x + 1, y});
                    vis.insert(to_string(x + 1) + ' ' + to_string(y));
                }
                if (y + 1 < m && !vis.count(to_string(x) + ' ' + to_string(y + 1)))
                {
                    pq.push({x, y + 1});
                    vis.insert(to_string(x) + ' ' + to_string(y + 1));
                }
            }
        }
        return -1;
    }
};