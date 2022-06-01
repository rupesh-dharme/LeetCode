class Compare {
public:
    bool operator() (vector<int> &lhs, vector<int> &rhs) {
        return lhs[0] + lhs[1] < rhs[0] + rhs[1];
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < min(k, n); i++) {
            for (int j = 0; j < min(k, m); j++) {
                int sum = nums1[i] + nums2[j];
                pq.push({nums1[i], nums2[j]});
                if (pq.size() > k) pq.pop(); 
                if (pq.size() && pq.size() == k && sum > pq.top()[0] + pq.top()[1]) break;
            }
        }
        vector<vector<int>> res;
        while (pq.size()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};