// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detectCycle(adj, i, visited)) return true;
            }
        }
        return false;
    }
    
    bool detectCycle(vector<int> adj[], int node, vector<int> &visited) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        visited[node] = 1;
        
        while (q.size()) {
            int curr = q.front().first;
            int prev = q.front().second;
            q.pop();
            for (auto nxt : adj[curr]) {
                if (!visited[nxt]) {
                    visited[nxt] = 1;
                    q.push({nxt, curr});
                } else {
                    if (prev != nxt) return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends