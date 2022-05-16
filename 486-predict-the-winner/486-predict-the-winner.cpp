class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (auto num : nums) total += num;
        int p1 = maximize(nums, 0, n-1);
        return p1*2 >= total;
    }
    int maximize(vector<int> &nums, int i, int j) {
        if (j == i) return nums[j];
        if (j == i+1) return max(nums[i], nums[j]);
        return max(nums[i] + min(maximize(nums, i+2, j), maximize(nums, i+1, j-1)), nums[j] + min(maximize(nums, i+1, j-1), maximize(nums, i, j-2)));
    }
};