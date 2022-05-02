class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int e = 0, o = 0, n = nums.size();
        for (auto num : nums) if (num % 2 == 0) o++;
        while (o < n) {
            if (nums[e] % 2 && nums[o] % 2 == 0) swap(nums[e], nums[o]);
            while (o < n && nums[o] % 2) o++;
            while (e < o && nums[e] % 2 == 0) e++;
        }
        return nums;
    }
};