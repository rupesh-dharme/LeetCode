// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
long long dp[1002][1002];
class Solution{
    public:
    long long maximumAmount(int arr[], int n){
        // Your code here
        memset(dp, -1, sizeof(dp));
        long long mx = maximise(arr, 0, n-1);
        return mx;
    }
    long long maximise(int arr[], int i, int j) {
        if (j == i+1) return max(arr[j], arr[i]);
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(arr[i] + min(maximise(arr, i+2, j), maximise(arr, i+1, j-1)), arr[j] + min(maximise(arr, i, j-2), maximise(arr, i+1, j-1)));
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends