class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mx = 0, n = p.size();
        for (int i = 1; i < n; i++) {
            if (p[i] - p[i-1] > mx) mx = p[i] - p[i-1];
            p[i] = p[i] < p[i-1] ? p[i] : p[i-1];
        }
        return mx;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mx = 0;
//         for (int i = 0; i < prices.size()-1; i++) {
//             for (int j = i+1; j < prices.size(); j++) {
//                 mx = max(mx, prices[j] - prices[i]);
//             }
//         }
//         return mx;
//     }
// };