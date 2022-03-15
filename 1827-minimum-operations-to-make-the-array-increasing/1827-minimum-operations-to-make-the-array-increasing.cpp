class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int prev = 0, result = 0;
        for (auto &num : nums) {
            if (num <= prev) {
                result += (prev-num+1);
                prev += 1;
            } else {
                prev = num;
            }
        }
        return result;
    }
};