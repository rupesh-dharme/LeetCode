class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        
        for (auto &time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].push_back({v, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        unordered_set<int> set;
        int t = 0;
        pq.push({0, k});
        while (pq.size()) {
            auto [delay, node] = pq.top(); pq.pop();
            
            if (set.count(node)) continue;
            set.insert(node);
            t = max(t, delay);
            
            for (auto next : graph[node]) {
                pq.push({delay + next.second, next.first});
                
            }
        }
        return set.size() == n ? t : -1;
    }
};