class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i+1 < n && nums[i+1]==nums[i]) {count++; i++;}
            int nn = subsets.size();
            for (int j = 1;j <= count; j++) {
                for (int k = 0; k < nn; k++) {
                    subsets.push_back(subsets[k]);
                    for (int l = 0; l < j; l++) {
                        subsets.back().push_back(nums[i]);
                    }
                }
            }
        }
        return subsets;
    }
};