// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    int c, d, ans = 0;
    bool found = false;
	public:
	void dfs(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<int> adj[]) {
	    if (found) return;
	    static int time = 0;
	    disc[u] = low[u] = time;
	    time++;
	    
	    for (auto v : adj[u]) {
	        if (disc[v] == -1) {
	            parent[v] = u;
	            dfs(v, disc, low, parent, adj);
	            low[u] = min(low[u], low[v]);
	            if (disc[u] < low[v]) {
	                if ((u == c && v == d) || (u == d && v == c)) {
	                    ans = 1;
	                    found = true;
	                }
	            }
	        }
	        else if (v != parent[u]) {
	            low[u] = min(low[u], disc[v]);
	        }
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int _c, int _d) 
    {
        c = _c;
        d = _d;
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        for (int u = 0; u < V; u++) {
            if (disc[u] == -1) dfs(u, disc, low, parent, adj);
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends