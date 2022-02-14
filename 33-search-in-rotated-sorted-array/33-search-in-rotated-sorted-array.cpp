class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            int num = (nums[0] <= target == nums[0] <= nums[mid]) ? nums[mid] : (target < nums[0]) ? INT_MIN : INT_MAX;
            if (num == target) return mid;
            else if (num < target) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};