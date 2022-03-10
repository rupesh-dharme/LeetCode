class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mnmx = 0, l = 0, r = nums.size()-1;
        while (l < r) {
            mnmx = max(mnmx, nums[l]+nums[r]);
            l++; r--;
        }
        return mnmx;
    }    
};