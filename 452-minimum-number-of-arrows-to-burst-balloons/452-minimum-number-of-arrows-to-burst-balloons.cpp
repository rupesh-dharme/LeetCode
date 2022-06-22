class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) { // sorting according to second value
        int n = points.size();
        if (n == 0) return 0;
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int count = 1;
        int end = points[0][1]; // first's end
        for (int i = 1; i < n; i++) {
            vector<int> point = points[i];
            if (point[0] <= end) {
                
            } else {
                end = point[1];
                count++;
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) { // sorting according to first value
//         if (points.size() == 0) return 0;
//         sort(points.begin(), points.end());
//         vector<int> p = points[0];
//         int count = 0, n = points.size();
//         for (int i = 1; i < n; i++) {
//             auto point = points[i];
//             if (point[0] <= p[1]) {
//                 count++;
//                 p[1] = min(p[1], point[1]);
//             } else {
//                 p = point;
//             }
//         }
//         return n - count;
//     }
// };