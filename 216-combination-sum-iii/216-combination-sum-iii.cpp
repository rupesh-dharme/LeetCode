class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        vector<int> nums(9);
        iota(nums.begin(), nums.end(), 1);
        recurse(nums, 0, n, combination, result, k);
        return result;
    }
    void recurse(vector<int> &nums, int i, int target, vector<int> &comb, vector<vector<int>> &result, int k) {
        if (comb.size() > k) return;
        if (i == nums.size()) {
            if (target == 0 && comb.size() == k) result.push_back(comb);
            return;
        }
        comb.push_back(nums[i]);
        recurse(nums, i+1, target-nums[i], comb, result, k);
        comb.pop_back();
        recurse(nums, i+1, target, comb, result, k);
    }
};