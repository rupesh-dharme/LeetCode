class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        
        sort(intervals.begin(), intervals.end());
        vector<int> iter = intervals[0];
        for (auto &it : intervals) {
            if (iter[1] >= it[0]) {
                iter[1] = max(iter[1], it[1]);
            } else {
                result.push_back(iter);
                iter = it;
            }
        }
        result.push_back(iter);
        return result;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> res;
//         sort(intervals.begin(), intervals.end());
//         vector<int> curr = intervals[0];
//         for (auto it: intervals) {
//             if (it[0] <= curr[1]) {
//                 curr[1] = max(curr[1],it[1]);

//             }else {
//                 res.push_back(curr);
//                 curr = it;
//             }
//         }
//         res.push_back(curr);
//         return res;
//     }
// };