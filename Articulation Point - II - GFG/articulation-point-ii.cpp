// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    void dfs(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap, vector<int> adj[]) {
        static int time = 0;
        disc[u] = low[u] = time++;
        int child = 0;
        
        for (auto v : adj[u]) {
            if (disc[v] == -1) {
                parent[v] = u;
                child++;
                if (parent[u] == -1 && child > 1) ap[u] = true;
                dfs(v, disc, low, parent, ap, adj);
                
                low[u] = min(low[u], low[v]);
                
                if (parent[u] != -1 && low[v] >= disc[u]) ap[u] = true;
            }
            else if (parent[u] != v) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<bool> ap(V, false);
        
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, disc, low, parent, ap, adj);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < V; i++) if (ap[i]) result.push_back(i);
        if (!result.size()) result.push_back(-1);
        return result;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends