class Solution {
public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//         int n = s.size();
//         vector<int> plates(n, 0), candles;
//         if (s[0] = '*') plates[0] = 1;
//         for (int i = 1; i < n; i++) {
//             if (s[i] == '*') {
//                 plates[i] = plates[i-1] + 1;
//             } else {
//                 plates[i] = plates[i-1];
//                 candles.push_back(i);
//             }
//         }
//         vector<int> result;
//         cout << endl;
//         for (auto query : queries) {
//             int l = *lower_bound(candles.begin(), candles.end(), query[0]);
//             auto it = upper_bound(candles.begin(), candles.end(), query[1]);
//             if (it == candles.begin()) {
//                 result.push_back(0);
//                 continue;
//             } else it--;
//             int r = *it;
//             if (l <= query[1] && r >= query[0]) result.push_back(plates[r] - plates[l]);
//             else result.push_back(0);
//         }
//         return result;
//     }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> A, res;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '|')
                A.push_back(i);
        for (int q = 0; q < queries.size(); ++q) {
            int i = lower_bound(A.begin(), A.end(), queries[q][0]) - A.begin();
            int j = upper_bound(A.begin(), A.end(), queries[q][1]) - A.begin() - 1;
            res.push_back(i < j ? (A[j] - A[i]) - (j - i) : 0);
        }
        return res;
    }
};