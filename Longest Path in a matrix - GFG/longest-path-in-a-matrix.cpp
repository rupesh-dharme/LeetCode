// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    int longest(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int DIR[] = {0, 1, 0, -1, 0};
        
        int temp = 1;
        for (int d = 0; d < 4; d++) {
            int x = i + DIR[d], y = j + DIR[d+1];
            if (x >= 0 && x < m && j >= 0 && j < n && matrix[x][y] > matrix[i][j]) {
                temp = max(temp, 1 + longest(matrix, dp, x, y));
            }
        }
        return dp[i][j] = temp;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1));
        int result = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (dp[i][j] == -1) {
                    result = max(result, longest(matrix, dp, i, j));
                } else {
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends