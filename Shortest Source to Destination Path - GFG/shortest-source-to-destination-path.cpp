// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        int steps = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        if (A[0][0] == 0) return -1;
        A[0][0] = 0;
        while (q.size()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x == X && y == Y) return steps;
                int DIR[] = {0, 1, 0, -1, 0};
                for (int d = 0; d < 4; d++) {
                    int a = x + DIR[d];
                    int b = y + DIR[d + 1];
                    
                    if (0 <= a && 0 <= b && a < A.size() && b < A[0].size() && A[a][b] == 1) {
                        A[a][b] = 0;
                        q.push({a, b});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends