// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


int CountPS(char s[], int n)
{
    //code here
    vector<vector<bool>> dp(n, vector<bool> (n, false));
    int count = 0;
    for (int d = 0; d < n; d++) {
        for (int i = 0, j = i + d; j < n; ++i, ++j) {
            if (d == 0) dp[i][j] = true;
            else if (d == 1) dp[i][j] = s[i] == s[j];
            else dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            if (d >= 1) count += dp[i][j];
        }
    }
    return count;
}