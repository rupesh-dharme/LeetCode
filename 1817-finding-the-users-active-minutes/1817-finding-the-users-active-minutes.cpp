class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> um;;
        vector<int> answer(k, 0);
        for (auto v : logs) {
            um[v[0]].insert(v[1]);
        }
        for (auto p : um) answer[p.second.size()-1]++;
        return answer;
    }
};