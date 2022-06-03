// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else {
                    dp[i][j] = 0;
                }
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
        
        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        // int mx = 0;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (s1[i-1] == s2[j-1]) {
        //             dp[i][j] = dp[i-1][j-1] + 1;
        //             mx = max(mx, dp[i][j]);
        //         }
        //         else dp[i][j] = 0;
        //     }
        // }
        // return mx;
        // int dp[n+1][m+1], mx = 0;
        // memset(dp, 0, sizeof(dp));
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (s1[i-1] == s2[j-1]) {
        //             dp[i][j] = dp[i-1][j-1] + 1;
        //             mx = max(mx, dp[i][j]);
        //         }
        //         else dp[i][j] = 0;
        //     }
        // }
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // return mx;
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1)); CODE FOR SUBSEQUENCE 
        // int dp[n+1][m+1];
        // memset(dp, 0, sizeof(dp));
        // // for (int i = 0; i <= n; i++) dp[i][0] = 0;
        // // for (int i = 0; i <= m; i++) dp[0][i] = 0
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        //         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //     }
        // }
        // return dp[n][m];

    // Solution() : dp(1001, vector<int> (1001, -1)) {}
    // int longestCommonSubstr (string s1, string s2, int n, int m)
    // {
    //     if (n == 0 || m == 0) return 0;
    //     if (dp[n][m] != -1) return dp[n][m];
    //     if (s1[n-1] == s2[m-1]) return dp[n][m] = (1 + longestCommonSubstr(s1, s2, n-1, m-1));
    //     return dp[n][m] = max(longestCommonSubstr(s1, s2, n-1, m), longestCommonSubstr(s1, s2, n, m-1));
    // }
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends