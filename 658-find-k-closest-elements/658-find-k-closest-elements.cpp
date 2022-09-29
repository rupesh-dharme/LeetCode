// class Compare {
// public:
    
// };

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto Compare = [&x](int &a, int &b) { 
            if (abs(a - x) == abs(b - x)) return a < b;
            return abs(a - x) < abs(b - x);
        };
        priority_queue<int, vector<int>, decltype(Compare)> pq(Compare);
        for (auto num : arr) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pq.top();
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};