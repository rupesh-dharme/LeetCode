class Solution {
public:
    int furthestBuilding(vector<int>& hts, int b, int l) {
        priority_queue<int> pq;
        int n = hts.size();
        for (int i = 0; i < n-1; i++) {
            int diff = hts[i+1] - hts[i];
            if (diff <= 0) continue;
            pq.push(diff);
            b -= diff;
            if (b < 0) {
                b += pq.top(); pq.pop();
                l--;
                if (l < 0 || b < 0) return i; 
            }
        }
        return n-1;
    }
};