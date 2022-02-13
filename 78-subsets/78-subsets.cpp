class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> arr;
        recurse(nums, 0, arr, res, n);
        return res;
    }
    void recurse(vector<int>& nums, int i, vector<int>& arr, vector<vector<int>>& res, int n) {
        if (i >= n) {res.push_back(arr); return;}
        recurse(nums, i+1, arr, res, n);
        arr.push_back(nums[i]);
        recurse(nums, i+1, arr, res, n);
        arr.pop_back();
    }
};