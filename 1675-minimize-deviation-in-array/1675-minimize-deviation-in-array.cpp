class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX;
        for (auto& num : nums) {
            if (num%2) {
                num*=2;
            }
            mn = min(mn, num);
            pq.push(num);
        }
        int diff = INT_MAX;
        while (pq.top()%2 == 0) {
            diff = min(diff, pq.top()-mn);
            mn = min(mn, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        diff = min(diff, pq.top()-mn);
        return diff;
    }
};