class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int e = 0, o = 0, n = nums.size();
        for (auto num : nums) num % 2 ? o++ : e++;
        o = e;
        e = 0;
        while (o < n) {
            if (nums[e] % 2 && nums[o] % 2 == 0) swap(nums[e], nums[o]);
            while (o < n && nums[o] % 2) o++;
            while (e < o && nums[e] % 2 == 0) e++;
        }
        return nums;
    }
};