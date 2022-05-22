class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<vector<int>> dp(n, vector<int> (n));
        
        for (int g = 0; g < n; g++) {
            for (int i = 0, j = i + g; j < n; i++, j++) {
                if (g == 0) dp[i][j] = 1;
                else if (g == 1) dp[i][j] = s[i] == s[j];
                else dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                count += dp[i][j];
            }
        }
        
        return count;
    }
};

// class Solution {
// public:
//     int palindrome(string &s, int i, int j, vector<vector<int>> &dp) {
//         if (i >= j) return 1;
//         if (dp[i][j] != -1) return dp[i][j];
        
//         if (s[i] != s[j]) return dp[i][j] = 0;
//         else return dp[i][j] = palindrome(s, i+1, j-1, dp);
//     }
//     int countSubstrings(string s) {
//         int count = 0, n = s.size();
//         vector<vector<int>> dp(n, vector<int> (n, -1));
//         for (int i = 0; i < n; ++i) {
//             for (int j = i; j < n; ++j) {
//                 if (palindrome(s, i, j, dp)) count++;
//             }
//         }
//         return count;
//     }
// };