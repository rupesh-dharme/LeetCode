class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<long long>> dp;
    unordered_map<char, int> um = {{'a', 1}, {'e', 2}, {'i', 4}, {'o', 2}, {'u', 1}};
public:
    int countVowelPermutation(int n) {
        dp.assign(5, vector<long long> (n + 1, 0));
        for (int i = 0; i < 5; i++) dp[i][1] = 1;
        for (int j = 1; j < n; j++) {
            dp[0][j + 1] += (dp[1][j] % mod + dp[2][j] % mod + dp[4][j] % mod) % mod;
            dp[1][j + 1] += (dp[0][j] % mod + dp[2][j] % mod) % mod;
            dp[2][j + 1] += (dp[1][j] % mod + dp[3][j] % mod) % mod;
            dp[3][j + 1] += dp[2][j] % mod;
            dp[4][j + 1] += (dp[2][j] + dp[3][j]) % mod;
        }
        long long res = 0;
        for (int i = 0; i < 5; i++) res += 1ll * dp[i][n];
        return res % mod;
    }
};