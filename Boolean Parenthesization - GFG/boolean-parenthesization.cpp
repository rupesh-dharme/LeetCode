// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dp[201][201][2];
public:
    int countWays(int N, string S){
        memset(dp, -1, sizeof dp);
        int res = solve(S, 0, S.size()-1, true);
        return res;
    }
    
    int solve(string &s, int i, int j, bool isTrue) {
        if (i == j) {
            if (s[i] == 'T') return isTrue == true;
            else return isTrue == false;
        }
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int ways = 0;
        for (int k = i+1; k < j; k+=2) {
            int temp = 0;
            if (s[k] == '&') {
                if (isTrue) temp += solve(s, i, k-1, true) * solve(s, k+1, j, true);
                else {
                    temp += solve(s, i, k-1, false) * solve(s, k+1, j, false);
                    temp += solve(s, i, k-1, true) * solve(s, k+1, j, false);
                    temp += solve(s, i, k-1, false) * solve(s, k+1, j, true);
                }
            } else if (s[k] == '|') {
                if (isTrue) {
                    temp += solve(s, i, k-1, true) * solve(s, k+1, j, true);
                    temp += solve(s, i, k-1, true) * solve(s, k+1, j, false);
                    temp += solve(s, i, k-1, false) * solve(s, k+1, j, true);
                }
                else temp += solve(s, i, k-1, false) * solve(s, k+1, j, false);
            } else {
                if (isTrue) {
                    temp += solve(s, i, k-1, true) * solve(s, k+1, j, false);
                    temp += solve(s, i, k-1, false) * solve(s, k+1, j, true);
                }
                else {
                    temp += solve(s, i, k-1, true) * solve(s, k+1, j, true);
                    temp += solve(s, i, k-1, false) * solve(s, k+1, j, false);
                }
            }
            ways += temp;
        }
        return dp[i][j][isTrue] = ways%1003;
    }
};






















// class Solution{
// public:
//     int dp[201][201][2];
//     int countWays(int N, string S){
//         memset(dp, -1, sizeof(dp));
//         int result = solve(S, 0, N-1, true);
//         return result;
//     }
//     int solve(string &s, int i, int j, bool isTrue) {
//         if (i > j) return 0;
//         if (i == j) {
//             if (s[i] == 'T') {
//                 if (isTrue == true) return 1;
//                 else return 0;
//             }
//             else {
//                 if (isTrue == false) return 1;
//                 else return 0;
//             }
//         }
//         if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
//         int ans = 0;
//         for (int k = i+1; k < j; k++) {
//             int lt = solve(s, i, k-1, true);
//             int lf = solve(s, i, k-1, false);
//             int rt = solve(s, k+1, j, true);
//             int rf = solve(s, k+1, j, false);
//             if (s[k] == '&') {
//                 if (isTrue) {
//                     ans += (lt * rt);
//                 } else {
//                     ans += (lf * rf + lt * rf + rt * lf);
//                 }
//             } else if (s[k] == '|') {
//                 if (isTrue) {
//                     ans += (lt * rt + lt * rf + rt * lf);
//                 } else {
//                     ans += (lf * rf);
//                 }
//             } else {
//                 if (isTrue) {
//                     ans += (lt * rf + lf * rt);
//                 } else {
//                     ans += (lf * rf + lt * rt); 
//                 }
//             }
//             ans = ans % 1003;
//         }
//         return dp[i][j][isTrue] = ans % 1003;
//     }
// };

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends