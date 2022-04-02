class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        vector<int> result, xrs;
        int xr = 0, n = nums.size();
        for (auto &num : nums) xr ^= num;
        for (int i = n-1; i >= 0; i--) {
            result.push_back(xr ^ (int)(pow(2, mb) - 1));
            xr ^= nums[i];
        }
        return result;
    }
};