class Compare {
public:
    bool operator() (vector<int> &lhs, vector<int> &rhs) {
        return (lhs[0]*lhs[0] + lhs[1]*lhs[1]) > (rhs[0]*rhs[0] + rhs[1]*rhs[1]);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for (auto &point : points) {
            pq.push(point);
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top());
            cout << pq.top()[0] << " " << pq.top()[1] << endl;
            pq.pop();
        }
        return res;
    }
};