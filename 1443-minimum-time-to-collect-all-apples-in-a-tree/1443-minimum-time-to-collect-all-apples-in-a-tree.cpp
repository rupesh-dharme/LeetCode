class Solution {
private:
    vector<bool> visited;
public:
    int recurse(int node, int &time, vector<int> adj[], vector<bool> &hasApple) {
        bool has = false;
        visited[node] = true;
        
        for (int next : adj[node]) {
            if (!visited[next]) {
                time += 1;
                bool present = recurse(next, time, adj, hasApple);
                has |= present;
                if (present) time += 1;
                else time -= 1;
            }
        }
        
        return has | hasApple[node];
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        visited.assign(n, false);
        int time = 0;
        recurse(0, time, adj, hasApple);
        return time;
    }
};