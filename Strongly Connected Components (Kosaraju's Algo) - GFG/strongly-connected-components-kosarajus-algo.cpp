// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    int count = 0;
	public:
	void dfs(int u, vector<bool> &vis, vector<int> adj[]) {
	    vis[u] = true;
	    for (auto v : adj[u]) if (!vis[v]) dfs(v, vis, adj);
	}
	void toposort(int u, vector<bool> &vis, stack<int> &topo, vector<int> adj[]) {
	    vis[u] = true;
	    for (auto v : adj[u]) {
	        if (!vis[v]) toposort(v, vis, topo, adj);
	    }
	    topo.push(u);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> topo;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) toposort(i, vis, topo, adj);
        }
        
        vector<int> trans[V];
        
        for (int i = 0; i < V; i++) {
            vis[i] = false;
            for (auto v : adj[i]) trans[v].push_back(i);
        }
        
        while (topo.size()) {
            int u = topo.top(); topo.pop();
            if (!vis[u]) {
                count++;
                dfs(u, vis, trans);
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends