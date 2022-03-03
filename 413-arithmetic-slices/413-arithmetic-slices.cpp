class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> dp(n, 0);
        dp[2] = nums[2]-nums[1] == nums[1]-nums[0] ? 1 : 0;
        int answer = dp[2];
        for (int i = 3; i < n; i++) {
            dp[i] = nums[i]-nums[i-1]==nums[i-1]-nums[i-2] ? dp[i-1]+1 : 0;
            answer += dp[i];
        }
        return answer;
    }
};