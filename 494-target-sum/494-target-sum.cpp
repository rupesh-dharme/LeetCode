class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0), diff = target;
        if(((sum - target) % 2 == 1) || (target > sum)) return 0;
        sum = (sum - diff)/2;
        vector<vector<int>> dp(n+1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};