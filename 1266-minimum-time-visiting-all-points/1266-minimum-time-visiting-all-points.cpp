class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(), time = 0;
        if (n == 1) return time;
        for (int i = 0; i < n-1; i++) {
            int cx = points[i][0];
            int cy = points[i][1];
            int nx = points[i+1][0];
            int ny = points[i+1][1];
            int m = min(abs(cx-nx), abs(cy-ny));
            time += m;
            time += abs(cx-nx) + abs(cy-ny) - 2*m;
        }
        return time;
    }
};