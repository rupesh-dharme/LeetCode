class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        unordered_map<int, int> um;
        for (auto num : nums) {
            if (um.find(k - num) != um.end() && um[k - num] > 0) {
                um[k - num]--;
                count++;
            }
            else um[num]++;
        }
        return count;
    }
};