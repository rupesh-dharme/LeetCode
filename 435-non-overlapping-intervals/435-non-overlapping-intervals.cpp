class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end());
        int count = 0, n = intervals.size();
        vector<int> prev = intervals[0];
        for (int i = 1; i < n; i++) {
            vector<int> interval = intervals[i];
            if (interval[0] < prev[1]) {
                count++;
                prev[1] = min(prev[1], interval[1]);
            } else {
                prev = intervals[i];
            }
        }
        return count;
    }
};