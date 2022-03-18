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
       for (int i = 0; i <= N; i++) dp[i][0] = 0;
       for (int i = 0; i <= W; i++) dp[0][i] = 0;
       for (int n = 1; n <= N; n++) {
           for (int w = 1; w <= W; w++) {
               if (wt[n-1] <= w) {
                   dp[n][w] = max(dp[n-1][w], val[n-1] + dp[n-1][w-wt[n-1]]);
               } else {
                   dp[n][w] = dp[n-1][w];
               }
           }
       }
       return dp[N][W];
    }
};

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