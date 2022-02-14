class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, ind = -1, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (nums[mid] == target) {
                ind = mid;
                break;
            } else if (nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        if (ind == -1) return {-1, -1};
        l = mid;
        r = mid;
        while (l-1 >=0 && nums[l-1]==nums[mid]) l--;
        while (r+1 < nums.size() && nums[r+1] == nums[mid]) r++;
        return {l, r};
    }
};