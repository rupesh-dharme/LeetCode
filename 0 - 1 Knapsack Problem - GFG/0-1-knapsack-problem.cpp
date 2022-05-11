// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int N)
    { 
       int dp[N+1][W+1];
       memset(dp, 0, sizeof(dp));
       for (int i = 1; i <= N; i++) {
           for (int j = 1; j <= W; j++) {
               if (wt[i-1] <= j) {
                   dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
               } else {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[N][W];
    }
};



























// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int N)
//     { 
//       int dp[N+1][W+1];
//       for (int i = 0; i <= N; i++) dp[i][0] = 0;
//       for (int i = 0; i <= W; i++) dp[0][i] = 0;
//       for (int n = 1; n <= N; n++) {
//           for (int w = 1; w <= W; w++) {
//               if (wt[n-1] <= w) {
//                   dp[n][w] = max(dp[n-1][w], val[n-1] + dp[n-1][w-wt[n-1]]);
//               } else {
//                   dp[n][w] = dp[n-1][w];
//               }
//           }
//       }
//     //   for (int i = 0; i <= N; i++) {
//     //       for (int j = 0; j <= W; j++) cout << dp[i][j] << " ";
//     //       cout << '\n';
//     //   }
//       return dp[N][W];
//     }
// };

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends