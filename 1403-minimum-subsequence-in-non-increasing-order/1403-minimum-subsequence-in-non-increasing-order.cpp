class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        vector<int> result;
        int sum = 0, total = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        for (int i = 0; i < n && 2 * sum <= total; i++) {
            sum += nums[i];
            result.push_back(nums[i]);
        }
        return result;
    }
};