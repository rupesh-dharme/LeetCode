// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Edge
{
    public:
    int wt, u, v;
    Edge(int _wt, int _u, int _v) {
        wt = _wt;
        u = _u;
        v = _v;
    }
};

bool comp(Edge a, Edge b) {
    return a.wt < b.wt;
}

class Solution
{
	public:
	int find(int child, vector<int>& parentof) {
        if (parentof[child] == child) return child;
        return find(parentof[child], parentof);
    }
    int unionn(int x, int y, vector<int>& parentof) {
        parentof[find(x, parentof)] = find(y, parentof);
    }
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<Edge> edges;
        for (int i = 0; i < V; i++) {
            for (auto v : adj[i]) {
                if (i < v[0]) edges.push_back(Edge(v[1], i, v[0]));
            }
        }
        sort(edges.begin(), edges.end(), comp);
        vector<int> parentof(V);
        iota(parentof.begin(), parentof.end(), 0);
        int answer = 0;
        for (auto edge : edges) {
            int wt = edge.wt, u = edge.u, v = edge.v;
            if (find(u, parentof) != find(v, parentof)) {
                answer += wt;
                unionn(u, v, parentof);
            }
        }
        return answer;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends