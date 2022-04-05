class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        for (auto &num : nums) {
            if (mp.count(num) && mp[num] == 1) {sum -= num; mp[num]++;}
            else if (mp.count(num) && mp[num] > 1) {}
            else {mp[num]++; sum += num;}
        }
        return sum;
    }
};