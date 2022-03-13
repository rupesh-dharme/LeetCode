class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int mx = 0;
        for (auto&v : rectangles) {
            mx = max(mx, min(v[0], v[1]));
        }
        int count = 0;
        for (auto&v : rectangles) {
            if (min(v[0], v[1]) >= mx) count++;
        }
        return count;
    }
};