class Solution {
private:
    unordered_map<int, vector<int>> adj;
    vector<vector<int>> bridges;
public:
    void dfs(int u, vector<int> &disc, vector<int> &low, vector<int> &parent) {
        static int time = 0;
        disc[u] = low[u] = time;
        time++;
        
        for (auto v : adj[u]) {
            if (disc[v] == -1) {
                parent[v] = u;
                dfs(v, disc, low, parent);
                low[u] = min(low[u], low[v]);
                if (disc[u] < low[v]) {
                    bridges.push_back({u, v});
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for (auto & conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        
        vector<int> disc(n, -1), low(n, -1), parent(n, -1);
        dfs(0, disc, low, parent);
        // for (int i = 0; i < n; i++) {
        //     if (disc[i] == -1) {
        //         dfs(i, disc, low, parent);
        //     }
        // }
        return bridges;
    }
};






































// class Solution {
// private:
//     unordered_map<int, vector<int>> adj;
// public:
//     void dfs(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<vector<int>> &bridges) {
//         static int time = 0;
//         disc[u] = low[u] = time;
//         time++;
        
//         for (auto v : adj[u]) {
//             if (disc[v] == -1) {
//                 parent[v] = u;
//                 dfs(v, disc, low, parent, bridges);
//                 low[u] = min(low[u], low[v]);
//                 if (low[v] > disc[u]) {
//                     bridges.push_back({u, v});
//                 }
//             }
//             else if (v != parent[u]) {
//                 low[u] = min(low[u], disc[v]);
//             }
//         }
        
//     }
//     void find_bridges(int V, vector<vector<int>> &bridges) {
//         vector<int> disc(V, -1), low(V, -1), parent(V, -1);

//         for (int v = 0; v < V; v++) {
//             if (disc[v] == -1) dfs(v, disc, low, parent, bridges);
//         }
//     }
//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
//         for (auto &connection : connections) {
//             adj[connection[0]].push_back(connection[1]);
//             adj[connection[1]].push_back(connection[0]);
//         }
//         vector<vector<int>> bridges;
//         find_bridges(n, bridges);
//         return bridges;
//     }
// };