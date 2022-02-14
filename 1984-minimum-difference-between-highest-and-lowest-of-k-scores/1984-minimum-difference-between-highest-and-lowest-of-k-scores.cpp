class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size(), diff = INT_MAX, l = 0, r = k-1;
        sort(nums.begin(), nums.end());
        while(r < n) {
            diff = min(diff, nums[r++]-nums[l++]);
        }
        return diff;
    }
};