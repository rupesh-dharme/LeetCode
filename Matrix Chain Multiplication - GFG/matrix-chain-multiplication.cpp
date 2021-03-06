// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// class Solution{
// public:
//     int dp[101][101];
//     Solution() {
//         memset(dp, -1, sizeof(dp));
//     }
//     int matrixMultiplication(int N, int arr[])
//     {
//         int ans = solve(arr, 1, N-1);
//         return ans;
//     }
//     int solve(int arr[], int i, int j) {
//         if (i >= j) return 0;
//         if (dp[i][j] != -1) return dp[i][j];
//         int mn = INT_MAX;
//         for (int k = i; k < j; k++) {
//             int cost = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
//             mn = min(mn, cost);
//         }
//         return dp[i][j] = mn;
//     }
// };

class Solution{
private:
    int dp[101][101];
public:
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof dp);
        int res = solve(arr, 1, N-1);
        return res;
    }
    
    int solve(int arr[], int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mn = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
            mn = min(mn, temp);
        }
        return dp[i][j] = mn;
    }
};































// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends