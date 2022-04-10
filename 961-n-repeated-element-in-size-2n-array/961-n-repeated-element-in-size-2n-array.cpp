class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            if (mp.count(num)) return num;
            mp[num]++;
        }
        return -1;
    }
};