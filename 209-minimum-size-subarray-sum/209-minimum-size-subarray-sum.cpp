class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, ans = INT_MAX;
        for (; r < n; r++) {
            sum += nums[r];
            while (sum < target && r < n-1) {
                r++;
                sum += nums[r];
            }
            while (sum >= target && l <= r) {
                ans = min(ans, r-l+1);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};