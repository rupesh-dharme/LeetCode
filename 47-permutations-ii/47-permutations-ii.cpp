class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        permute(nums, nums.size(), 0, result);
        return result;
    }
    void permute(vector<int>& nums, int n, int i, vector<vector<int>>& result) {
        if (i == n) {
            result.push_back(nums);
            return;
        }
        unordered_map<int, int> count;
        for (int j = i; j < n; j++) {
            if (count[nums[j]] == 1) continue;
            count[nums[j]] = 1;
            swap(nums[j], nums[i]);
            permute(nums, n, i+1, result);
            swap(nums[j], nums[i]);
        }
    }
};