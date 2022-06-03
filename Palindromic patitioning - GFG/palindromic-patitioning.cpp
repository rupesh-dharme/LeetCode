// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dp[501][501];
public:
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof dp);
        int res = solve(str, 0, str.size()-1);
        return res;
    }
    
    int solve(string &str, int i, int j) {
        if (i >= j || palindrome(str, i, j)) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mn = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = solve(str, i, k) + solve(str, k+1, j) + 1;
            mn = min(temp, mn);
        }
        return dp[i][j] = mn;
    }
    
    bool palindrome(string &str, int i, int j) {
        while (i < j) {
            if (str[i++] != str[j--]) return false;
        }
        return true;
    }
};
























// class Solution{
// public:
//     int dp[501][501];
//     Solution() {
//         memset(dp, -1, sizeof(dp));
//     }
    
//     int palindromicPartition(string str)
//     {
//         int n = str.size();
//         int cuts = solve(str, 0, n-1);
//         return cuts;
//     }
    
//     int solve(string &str, int i, int j) {
//         if (i >= j || isPal(str, i, j)) return 0;
//         if (dp[i][j] != -1) return dp[i][j];
//         int count = INT_MAX;
//         for (int k = i; k < j; k++) {
//             int temp = solve(str, i, k) + solve(str, k+1, j) + 1;
//             count = min(count, temp);
//         }
//         return dp[i][j] = count;
//     }
    
//     bool isPal(string &s, int i, int j) {
//         while (i < j) {
//             if (s[i++] != s[j--]) return false;
//         }
//         return true;
//     }
// };

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends