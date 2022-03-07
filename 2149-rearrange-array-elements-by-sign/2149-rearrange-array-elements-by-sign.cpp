class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> e, o;
        for (auto num : nums) {
            if (num < 0) o.push_back(num);
            else e.push_back(num);
        }
        int n = nums.size();
        nums.clear();
        for (int i = 0; i < n/2; i++) {
            nums.push_back(e[i]);
            nums.push_back(o[i]);
        }
        return nums;
    }
};