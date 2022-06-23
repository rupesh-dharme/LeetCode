class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& interval) {
        if (!intervals.size()) return {interval};
        
        intervals.insert(upper_bound(intervals.begin(), intervals.end(), interval, [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        }), interval);
        
        vector<vector<int>> result;
        auto p = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= p[1]) {
                p[1] = max(intervals[i][1], p[1]);
            }
            else {
                result.push_back(p);
                p = intervals[i];
            }
        }
        result.push_back(p);
        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& interval) {
//         if (!intervals.size()) return {interval};
//         // bool inserted = false;
//         // for (auto it = intervals.begin(); it != intervals.end(); it++) {
//         //     if ((*it)[0] >= interval[0]) {
//         //         inserted = true;
//         //         intervals.insert(it, interval);
//         //     }
//         // }
//         // if (!inserted) intervals.push_back(interval);
        
        
//         // intervals.push_back(interval);
//         // sort(intervals.begin(), intervals.end());
        
//         intervals.insert(upper_bound(intervals.begin(), intervals.end(), interval, [](const vector<int> &a, const vector<int> &b) {
//             return a[0] < b[0];
//         }), interval);
//         // vector<vector<int>> result;
//         // auto p = intervals[0];
//         // for (int i = 1; i < intervals.size(); i++) {
//         //     if (intervals[i][0] <= p[1]) {
//         //         p[1] = max(intervals[i][1], p[1]);
//         //     }
//         //     else {
//         //         result.push_back(p);
//         //         p = intervals[i];
//         //     }
//         // }
//         // result.push_back(p);
//         return intervals;
//     }
// };