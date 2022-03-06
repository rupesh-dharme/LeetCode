class Solution {
public:
    int robMax(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(robMax(nums, i+1, dp), robMax(nums, i+2, dp) + nums[i]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp1(101, -1), dp2(101, -1), ifirst, ilast;
        for (int i = 0; i < n-1; i++) {
            ifirst.push_back(nums[i]);
            ilast.push_back(nums[i+1]);
        }
        return max(robMax(ifirst, 0, dp1), robMax(ilast, 0, dp2));
    }
};