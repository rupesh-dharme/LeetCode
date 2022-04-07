class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto &stone : stones) pq.push(stone);
        while (pq.size() > 1) {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            if (s1 != s2) {
                int stone = s1 > s2 ? s1 - s2 : s2 - s1;
                pq.push(stone);
            } 
        }
        return pq.size() ? pq.top() : 0;
    }
};