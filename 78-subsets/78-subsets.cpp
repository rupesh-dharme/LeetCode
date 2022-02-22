class Solution { // Works iterative
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subsets;
        subsets.push_back({});
        for (int i = 0; i < n; i++) {
            int k = subsets.size();
            for (int j = 0; j < k; j++) {
                subsets.push_back(subsets[j]);
                subsets.back().push_back(nums[i]);
            }
        }
        return subsets;
    }
};

// class Solution { // Works recursion again
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> subsets;
//         vector<int> subset;
//         recurse(nums, 0, subset, subsets);
//         return subsets;
//     }
//     void recurse(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& subsets) {
//         if (i == nums.size()) {subsets.push_back(subset); return;}
//         recurse(nums, i+1, subset, subsets);
//         subset.push_back(nums[i]);
//         recurse(nums, i+1, subset, subsets);
//         subset.pop_back();
//     }
// };

// class Solution { //Works recursion
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> res;
//         vector<int> arr;
//         recurse(nums, 0, arr, res, n);
//         return res;
//     }
//     void recurse(vector<int>& nums, int i, vector<int>& arr, vector<vector<int>>& res, int n) {
//         if (i >= n) {res.push_back(arr); return;}
//         recurse(nums, i+1, arr, res, n);
//         arr.push_back(nums[i]);
//         recurse(nums, i+1, arr, res, n);
//         arr.pop_back();
//     }
// };