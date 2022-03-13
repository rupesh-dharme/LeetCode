class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(), time = 0;
        if (n == 1) return time;
        for (int i = 0; i < n-1; i++) {
            int cx = points[i][0], cy = points[i][1], nx = points[i+1][0], ny = points[i+1][1];
            time += max(abs(cx-nx), abs(cy-ny));
        }
        return time;
    }
};