class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> sources;
        for (auto& path : paths) {
            sources[path[0]]++;
        }
        for (auto& path : paths) {
            if (sources.find(path[1]) == sources.end()) return path[1];
        }
        return ""; 
    }
};