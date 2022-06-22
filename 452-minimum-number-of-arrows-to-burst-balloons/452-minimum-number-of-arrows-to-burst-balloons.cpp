class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end());
        vector<int> p = points[0];
        int count = 0, n = points.size();
        for (int i = 1; i < n; i++) {
            auto point = points[i];
            if (point[0] <= p[1]) {
                count++;
                p[1] = min(p[1], point[1]);
            } else {
                p = point;
            }
        }
        return n - count;
    }
};