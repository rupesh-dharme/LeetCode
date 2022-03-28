// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1;
//         while (l <= r) {
//             int mid = l + (r - l)/2;
//             if (nums[mid] == target) return mid;
//             if (nums[l] <= nums[mid]) {
//                 if (nums[l] <= target && target < nums[mid]) r = mid - 1;
//                 else l = mid + 1;
//             } else {
//                 if (nums[mid] < target && target <= nums[r]) l = mid +1;
//                 else r = mid = 1;
//             }
//         }
//         return -1;
//     }
// };

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