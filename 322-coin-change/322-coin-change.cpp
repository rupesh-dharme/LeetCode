class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        for (int i = 1; i <= amount; i++) dp[0][i] = INT_MAX - 1;
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i-1] <= j) {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    }
};










































// int tab[12][10001];

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int Max = amount + 1;
//         vector<int> dp(amount + 1, Max);
//         dp[0] = 0;
//         for (int i = 1; i <= amount; i++) {
//             for (int j = 0; j < coins.size(); j++) {
//                 if (coins[j] <= i) {
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                 }
//             }
//         }
//         return dp[amount] > amount ? -1 : dp[amount];
//     }
// };