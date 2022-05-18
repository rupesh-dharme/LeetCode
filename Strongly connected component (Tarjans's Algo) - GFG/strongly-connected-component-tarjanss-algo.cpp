// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    vector<vector<int>> res;
	public:
	void dfs(int u, stack<int> &s, vector<int> adj[], vector<int> &vis) {
	    vis[u] = 1;
	    for (auto v : adj[u]) {
	        if (!vis[v]) dfs(v, s, adj, vis);
	    }
	    s.push(u);
	}
	
	void revdfs(int node, vector<int> adj[], vector<int> &ssc, vector<int> &vis) {
	    vis[node] = 1;
	    ssc.push_back(node);
	    for (auto v : adj[node]) {
	        if (!vis[v]) revdfs(v, adj, ssc, vis);
	    }
	}
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        stack<int> topo;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs(i, topo, adj, vis);
        }
        
        vector<int> trans[V];
        
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto v : adj[i]) {
                trans[v].push_back(i);
            }
        }
        
        vector<int> ssc;
        while (topo.size()) {
            int node = topo.top();
            topo.pop();
            if (!vis[node]) {
                ssc.clear();
                revdfs(node, trans, ssc, vis);
                sort(ssc.begin(), ssc.end());
                res.push_back(ssc);
            }
        }
        sort(res.begin(), res.end());
        return res;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends