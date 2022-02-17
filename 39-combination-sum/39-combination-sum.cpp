class Solution {
public:
    void comb(vector<int>& arr, int i, vector<int>& candidates, int n, int target, vector<vector<int>>& res) {
        if (target < 0 || i == n) return;
        if (target == 0) {
            res.push_back(arr);
            return;
        }
        comb(arr, i+1, candidates, n, target, res);
        arr.push_back(candidates[i]);
        comb(arr, i, candidates, n, target-candidates[i], res);
        arr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;
        comb(arr, 0, candidates, candidates.size(), target, res);
        return res;
    }
};