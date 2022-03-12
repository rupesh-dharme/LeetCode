class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        int curr = 0;
        for (auto num : nums) {
            curr += num;
            mx = max(mx, curr);
            if (curr < 0) curr = 0;
        }
        return mx;
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int mx = INT_MIN;
//         int sum = 0;
//         for (auto num : nums) {
//             sum += num;
//             mx = max(sum, mx);
//             if (sum < 0) sum = 0;
//         }
//         return mx;
//     }
// };

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) { //       TLE
//         int mx = INT_MIN, n = nums.size();
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];
//                 mx = mx > sum ? mx : sum;
//             }
//         }
//         return mx;
//     }
// };