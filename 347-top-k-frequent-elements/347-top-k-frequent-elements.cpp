class Compare {
public:
    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (auto num : nums) um[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto &p : um) {
            pq.push(p);
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (pq.size()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> map;
//         for(int num : nums){
//             map[num]++;
//         }
        
//         vector<int> res;
//         priority_queue<pair<int,int>> pq; 
//         for(auto it = map.begin(); it != map.end(); it++){
//             pq.push(make_pair(it->second, it->first));
//             if(pq.size() > (int)map.size() - k){
//                 res.push_back(pq.top().second);
//                 pq.pop();
//             }
//         }
//         return res;
//     }
};