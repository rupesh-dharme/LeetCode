class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(20001, 0);
        for (auto num : nums) {
            count[num]+=num;
        }
        int take = 0, skip = 0, n = nums.size();
        for (int i = 0; i < 20001; i++) {
            int takei = skip + count[i];
            int skipi = max(take, skip);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};