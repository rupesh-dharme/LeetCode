class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        recurse(0, graph.size()-1, graph, path, res);
        return res;
    }
    void recurse(int i, int d, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>> & res) {
        if (i == d) {
            res.push_back(path);
            return;
        }
        for (auto node : graph[i]) {
            path.push_back(node);
            recurse(node, d, graph, path, res);
            path.pop_back();
        }
    }
};