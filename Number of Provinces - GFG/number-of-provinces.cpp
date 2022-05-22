// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int u, vector<vector<int>> &adj, vector<int> &vis) {
        vis[u] = 1;
        for (int v = 0; v < adj.size(); v++) {
            if (adj[u][v] && !vis[v]) dfs(v, adj, vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int count = 0;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends