class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            xr ^= i;
            xr ^= nums[i];
        }
        xr ^= n;
        return xr;
    }
};