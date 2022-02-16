class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int front = i+1, back = nums.size()-1;
            int target = -nums[i];
            while (front < back) {
                if(nums[front]+nums[back] < target) front++;
                else if (nums[front]+nums[back] > target) back--;
                else {
                    res.push_back({nums[i], nums[front], nums[back]});
                    while (++front < back && nums[front-1]==nums[front]);
                    while (--back > front && nums[back+1]==nums[back]);
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};