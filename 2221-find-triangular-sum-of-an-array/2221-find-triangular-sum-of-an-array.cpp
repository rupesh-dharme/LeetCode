class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp;
        while (nums.size() > 1) {
            int n = nums.size();
            for (int i = 1; i < n; i++) {
                temp.push_back((nums[i] + nums[i-1]) % 10);
            }
            nums = temp;
            temp.clear();
        }
        return nums[0];
    }
};