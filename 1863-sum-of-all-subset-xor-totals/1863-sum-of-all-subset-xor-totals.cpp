class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0, xr = 0;
        recurse(nums, 0, nums.size(), xr, sum);
        return sum;
    }
    void recurse(vector<int>& nums, int i, int n, int& xr, int& sum) {
        if (i == n) {
            sum += xr;
            return;
        }
        xr ^= nums[i];
        recurse(nums, i+1, n, xr, sum);
        xr ^= nums[i];
        recurse(nums, i+1, n, xr, sum);
    }
};