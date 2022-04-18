class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int present[1001] = {0};
        for (auto num : nums) {
            present[num] = 1;
        }
        while (original <= 1000 && present[original]) original *= 2;
        return original;
    }
};