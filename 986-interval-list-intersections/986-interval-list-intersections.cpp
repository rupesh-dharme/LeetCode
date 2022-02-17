class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            auto pa = a[i];
            auto pb = b[j];
            if (pa[0]<=pb[1] && pa[1]>=pb[0]) {
                res.push_back({max(pa[0], pb[0]), min(pa[1], pb[1])});
            }
            pa[1] > pb[1] ? j++ : i++;
        }
        return res;
    }
};