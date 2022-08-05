class Solution {
private:
    vector<int> dp;
public:
    int solve(vector<int> &nums, int target, vector<int> &path) {
        if (target < 0) return 0;
        if (target == 0) {
            for (auto p : path) cout << p << " ";
            cout << endl;
            return 1;
        }
        if (dp[target] != -1) return dp[target];
        int res = 0;
        for (auto num : nums) {
            path.push_back(num);
            res += solve(nums, target - num, path);
            path.pop_back();
        }
        return dp[target] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> path;
        dp.assign(target + 1, -1);
        return solve(nums, target, path);
    }
};