class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> count(n, 0);
        for (auto& edge : edges) {
            count[edge[1]] = 1;
        }
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (!count[i]) {
                count[m++] = i;
            }
        }
        count.resize(m);
        return count;
    }
};