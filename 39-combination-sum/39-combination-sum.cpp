class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;
        recurse(candidates, 0, candidates.size(), target, combination, combinations);
        return combinations;
    }
    void recurse(vector<int>& candidates, int i, int n, int target, vector<int>& combination, vector<vector<int>>& combinations) {
        if (target==0) {
            combinations.push_back(combination);
            return;
        }
        if (target<0 || i==n) return;
        combination.push_back(candidates[i]);
        recurse(candidates, i, n, target-candidates[i], combination, combinations);
        combination.pop_back();
        recurse(candidates, i+1, n, target, combination, combinations);
    }
};





































// class Solution {
// public:
//     void comb(vector<int>& arr, int i, vector<int>& candidates, int n, int target, vector<vector<int>>& res) {
//         if (target < 0 || i == n) return;
//         if (target == 0) {
//             res.push_back(arr);
//             return;
//         }
//         comb(arr, i+1, candidates, n, target, res);
//         arr.push_back(candidates[i]);
//         comb(arr, i, candidates, n, target-candidates[i], res);
//         arr.pop_back();
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> arr;
//         vector<vector<int>> res;
//         comb(arr, 0, candidates, candidates.size(), target, res);
//         return res;
//     }
// };