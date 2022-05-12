class Compare {
public:
    bool operator() (pair<char, int> &lhs, pair<char, int> &rhs) {
        return lhs.second < rhs.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) mp[ch]++;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        for (auto p : mp) pq.push(p);
        string res;
        while (pq.size()) {
            auto [ch, count] = pq.top(); pq.pop();
            while (count--) {
                res += ch;
            }
        }
        return res;
    }
};