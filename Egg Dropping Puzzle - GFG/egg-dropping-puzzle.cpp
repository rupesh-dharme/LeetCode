// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int dp[201][201];
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        memset(dp, -1, sizeof(dp));
        int result = solve(n, k);
        return result;
    }
    
    int solve(int n, int k) {
        if (n == 1) return k;
        if (k == 1 || k == 0) return k;
        if (dp[n][k] != -1) return dp[n][k];
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++) {
            int temp = 1 + max(solve(n-1, i-1), solve(n, k - i));
            ans = min(ans, temp);
        }
        return dp[n][k] = ans;
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends