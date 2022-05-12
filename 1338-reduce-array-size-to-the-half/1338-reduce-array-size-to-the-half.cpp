class Compare {
public:
    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second < rhs.second;
    }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (auto num : arr) mp[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto p : mp) pq.push(p);
        int result = 0;
        int k = 0;
        while (2*k < n) {
            auto [num, count] = pq.top(); pq.pop();
            k += count;
            result++;
        }
        return result;
    }
};