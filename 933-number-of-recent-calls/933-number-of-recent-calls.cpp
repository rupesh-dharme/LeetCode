class RecentCounter {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while (pq.size() && pq.top() < t-3000) pq.pop();
        pq.push(t);
        return pq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */