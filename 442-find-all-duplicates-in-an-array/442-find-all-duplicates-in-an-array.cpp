class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i])-1] < 0) result.push_back(abs(nums[i]));
            else nums[abs(nums[i])-1] = -(nums[abs(nums[i])-1]);
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> result;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n-1; i++) {
//             if (nums[i] == nums[i+1]) {
//                 result.push_back(nums[i]);
//             }
//         }
//         return result;
//     }
// };