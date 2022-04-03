class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i;
        for (i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) break;
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j;
        for (j = n-1; j > i; j--) if (nums[j] > nums[i]) break;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(), nums.end());
//     }
// };