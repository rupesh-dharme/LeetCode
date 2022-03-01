class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> us;
        for (auto edge : edges) {
            if (us.count(edge[0])) return edge[0];
            if (us.count(edge[1])) return edge[1];
            us.insert(edge[0]); us.insert(edge[1]);
        }
        return -1;
    }
};