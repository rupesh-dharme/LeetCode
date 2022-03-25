class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1]-a[0] > b[1]-b[0];
        });
        int result = 0, n = costs.size();
        for (int i = 1; i <= n; i++) {
            if (i <= n/2) {
                result += costs[i-1][0];
            } else {
                result += costs[i-1][1];
            }
        }
        return result;
    }
};