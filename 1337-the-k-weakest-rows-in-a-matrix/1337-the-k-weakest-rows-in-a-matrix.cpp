class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        set<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.insert({count(mat[i].begin(), mat[i].end(), 1), i});
        }
        vector<int> result;
        for (auto it = v.begin(); k > 0 && it != v.end(); k--, it++) {
            result.push_back(it->second);
        }
        return result;
    }
};