class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        allPaths(graph, 0, res, path);
        return res;
    }
    void allPaths(vector<vector<int>>& graph, int node, vector<vector<int>>& res, vector<int>& path) {
        if (node == graph.size()-1) {
            res.push_back(path);
            return;
        }
        for (auto idx : graph[node]) {
            path.push_back(idx);
            allPaths(graph, idx, res, path);
            path.pop_back();
        }
    }
};