class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int st = nums.size(), en = -1, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (sorted[i] != nums[i]) st == n ? st = i : en = i;
        }
        return st > en ? 0 : en - st + 1;
    }
};