// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {// BFS solution
  public:
    bool bfs(int u, vector<int> adj[], vector<int> &vis) {
        queue<pair<int, int>> q;
        q.push({u, -1});
        vis[u] = true;
        
        while (q.size()) {
            int u = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push({v, u});
                } else if (v != par) return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) if (bfs(i, adj, vis)) return true;
        }
        return false;
    }
};


// class Solution {// DFS solution
//   public:
//     bool dfs(int u, int par, vector<int> adj[], vector<bool> &vis) {
//         vis[u] = true;
        
//         for (auto v : adj[u]) {
//             if (!vis[v]) {
//                 if (dfs(v, u, adj, vis)) return true;
//             } else if (v != par) return true;
//         }
        
//         return false;
//     }
//     // Function to detect cycle in an undirected graph.
//     bool isCycle(int V, vector<int> adj[]) {
//         // Code here
//         vector<bool> vis(V, false);
        
//         for (int i = 0; i < V; i++) {
//             if (!vis[i]) if (dfs(i, -1, adj, vis)) return true;
//         }
        
//         return false;
//     }
// };



























// class Solution {
//   public:
//     // Function to detect cycle in an undirected graph.
//     bool isCycle(int V, vector<int> adj[]) {
//         // Code here
//         vector<int> visited(V, 0);
//         for (int i = 0; i < V; i++) {
//             if (!visited[i]) {
//                 if (detectCycle(adj, i, visited)) return true;
//             }
//         }
//         return false;
//     }
    
//     bool detectCycle(vector<int> adj[], int node, vector<int> &visited) {
//         queue<pair<int, int>> q;
//         q.push({node, -1});
//         visited[node] = 1;
        
//         while (q.size()) {
//             int curr = q.front().first;
//             int prev = q.front().second;
//             q.pop();
//             for (auto nxt : adj[curr]) {
//                 if (!visited[nxt]) {
//                     visited[nxt] = 1;
//                     q.push({nxt, curr});
//                 } else {
//                     if (prev != nxt) return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

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