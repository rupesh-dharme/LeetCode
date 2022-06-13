class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int count = 0, n = nums.size();
        unordered_set<string> us;
        for (int i = 0; i < n; i++) {
            int c = 0;
            string sub;
            for (int j = i; j < n; j++) {
                if (nums[j] % p == 0) c++;
                if (c > k) break;
                if (sub.size()) sub += ('#' + to_string(nums[j]));
                else sub = to_string(nums[j]);
                if (us.count(sub) == 0) count++;
                us.insert(sub);
            }
        }
        return count;
    }
};