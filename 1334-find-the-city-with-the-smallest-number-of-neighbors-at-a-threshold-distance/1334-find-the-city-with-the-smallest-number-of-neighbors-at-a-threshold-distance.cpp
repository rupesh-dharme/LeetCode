class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dist(n, vector<int> (n, 20001));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (auto &edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        
        for (int k = 0; k < n; k++) {
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
            
        }
        
        // for (auto v : dist) {
        //     for (auto ele : v) cout << ele << " ";
        //     cout << endl;
        // }
        
        int mn = INT_MAX;
        int city;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for(auto a : dist[i]) if (a <= d) count++;
            if (count <= mn) {
                mn = count;
                city = i;
            }
        }
        return city;
    }
};