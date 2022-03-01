class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector<vector<int>> result;
        vector<int> combination;
        combinations(c, 0, c.size(), combination, result, target);
        return result;
    }
    void combinations(vector<int>& c, int i, int n, vector<int>& combination, vector<vector<int>>& result, int target) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        // unordered_set<int> us;
        for (int j = i; j < n; j++) {
            if (c[j]> target) break;
            if (j != i && c[j] == c[j-1]) continue;
            // if (us.count(c[j])) continue;
            // us.insert(c[j]);
            // combinations(c, i+1, n, combination, result, target);
            combination.push_back(c[j]);
            combinations(c, j+1, n, combination, result, target-c[j]);
            combination.pop_back();
        }
    }
};