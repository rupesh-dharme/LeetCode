class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return {to_string(nums[0])};
        vector<string> v;
        int l = 0;
        int r = 0;
        while (r < n-1) {
            if (nums[r] == nums[r+1] - 1) {
                r++;
            }
            else {
                if (l == r) {
                    v.push_back(to_string(nums[l]));
                    l++;
                    r++;
                }
                else {
                    v.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
                    r++;
                    l = r;
                } 
            }
        }
        if (l == r) {
            v.push_back(to_string(nums[l]));
        }
        else {
            v.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
        } 
        return v;
    }
};