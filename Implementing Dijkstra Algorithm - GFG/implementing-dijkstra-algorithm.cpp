// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // bool vis[V] = {false};
        vector<int> distTo(V, INT_MAX);
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        distTo[S] = 0;
        pq.push({0, S});
        
        while (!pq.empty()) {
            int dist = pq.top().first, node = pq.top().second; 
            pq.pop();
            // vis[node] = true;
            
            for (auto v : adj[node]) {
                int nxt = v[0], wt = v[1];
                if (dist + wt < distTo[nxt]) {
                    distTo[nxt] = dist + wt;
                    pq.push({distTo[nxt], nxt});
                }
            }
        }
        
        return distTo;
    }
};

// class Solution
// {
// 	public:
// 	//Function to find the shortest distance of all the vertices
//     //from the source vertex S.
//     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
//     {
//         vector<int> distTo(V, INT_MAX);
//         distTo[S] = 0;
//         queue<pair<int, int>> q;
//         q.push({S, 0});
//         while (!q.empty()) {
//             auto node = q.front().first;
//             auto dist = q.front().second;
//             q.pop();
//             for (auto next : adj[node]) {
//                 auto nextNode = next[0];
//                 auto nextDist = next[1];
//                 if (distTo[nextNode] > dist + nextDist) {
//                     distTo[nextNode] = dist + nextDist;
//                     q.push({nextNode, distTo[nextNode]});
//                 }
//             }
//         }
//         return distTo;
//     }
// };

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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends