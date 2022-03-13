// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    vector<vector<int>> dp(n, vector<int>(m, 0));
	    for (int i = 0; i < m; i++) dp[0][i] = 1;
	    for (int i = 0; i < n; i++) dp[i][0] = 1;
	    set<pair<int, int>> s;
	    for (auto& v : blocked_cells) {
	        dp[v[0]-1][v[1]-1] = 0;
	        s.insert({v[0]-1, v[1]-1});
	    }
	    for (int i = 0; i < m; i++) {
	        if (dp[0][i] == 0) {
	            for (int j = i+1; j < m; j++) dp[0][j] = 0;
	            break;
	        }
	    }
	    for (int i = 0; i < n; i++) {
	        if (dp[i][0] == 0) {
	            for (int j = i+1; j < n; j++) dp[j][0] = 0;
	            break;
	        }
	    }
	    for (int r = 1; r < n; r++) {
	        for (int c = 1; c < m; c++) {
	            if (s.find({r, c}) != s.end()) dp[r][c] = 0;
	            else dp[r][c] = (dp[r-1][c] + dp[r][c-1])%(1000000007);
	        }
	    }
	    return dp[n-1][m-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends