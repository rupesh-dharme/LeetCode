class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> stk;
        int n = temp.size();
        vector<int> result(n, 0);
        stk.push({temp[0], 0});
        for (int i = 1; i < n; i++) {
            while (stk.size() && stk.top().first < temp[i]) {
                result[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({temp[i], i});
        }
        return result;
    }
};