class Compare {
public:
    bool operator() (pair<string, int> &a, pair<string, int> &b) {
        if (a.second > b.second) return true;
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto word : words) mp[word]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for (auto p : mp) {
            pq.push(p);
            if (pq.size() > k) pq.pop();
        }
        vector<string> res;
        while(pq.size()) {
            res.push_back(pq.top().first);
            // cout << pq.top().first << " " << pq.top().second << endl;
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};