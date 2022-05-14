class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), i;
        stack<pair<int, int>> stk;
        unordered_set<int> done, ind;
        vector<int> res(n, -1);
        for (int j = 0; j < 2 * n; j++) {
            i = j % n;
            while (stk.size() && stk.top().first < nums[i]) {
                done.insert(i);
                res[stk.top().second] = nums[i];
                stk.pop();
            }
            if (ind.count(i) == 0) {
                ind.insert(i);
                stk.push({nums[i], i});
            }
        }
        return res;
    }
};