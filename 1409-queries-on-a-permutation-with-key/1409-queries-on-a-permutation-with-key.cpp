class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v(m);
        iota(v.begin(), v.end(), 1);
        vector<int> res;
        int n = queries.size();
        for (int i = 0; i < n; i++) {
            auto it = find(v.begin(), v.end(), queries[i]);
            int temp = *it;
            res.push_back(it-v.begin());
            v.erase(it);
            v.insert(v.begin(), temp);
        }
        return res;
    }
};