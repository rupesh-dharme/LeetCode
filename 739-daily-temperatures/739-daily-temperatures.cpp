class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> result(n, 0);
        for (int i = n-1; i >= 0; --i) {
            int j = i+1;
            while (j < n && temp[i] >= temp[j]) {
                if (result[j] > 0) j += result[j];
                else j = n;
            }
            if (j < n) result[i] = j - i;
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temp) {
//         stack<pair<int, int>> stk;
//         int n = temp.size();
//         vector<int> result(n, 0);
//         stk.push({temp[0], 0});
//         for (int i = 1; i < n; i++) {
//             while (stk.size() && stk.top().first < temp[i]) {
//                 int ind = stk.top().second;
//                 result[ind] = i - ind;
//                 stk.pop();
//             }
//             stk.push({temp[i], i});
//         }
//         return result;
//     }
// };