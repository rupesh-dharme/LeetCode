// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    int count = 0;
	public:
	
	void dfs(int node, vector<int> adj[], vector<int> &vis) {
	    vis[node] = 1;
	    for (auto v : adj[node]) {
	        if (!vis[v]) dfs(v, adj, vis);
	    }
	}
	void toposort(int node, vector<int> adj[], stack<int> &topo, vector<int> &vis) {
	    vis[node] = 1;
	    for (auto v : adj[node]) {
	        if (!vis[v]) toposort(v, adj, topo, vis);
	    }
	    topo.push(node);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> topo;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) toposort(i, adj, topo, vis);
        }
        
        vector<int> trans[V];
        
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto v : adj[i]) trans[v].push_back(i);
        }
        
        while (topo.size()) {
            int node = topo.top();
            topo.pop();
            if (!vis[node]) {
                count++;
                dfs(node, trans, vis);
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