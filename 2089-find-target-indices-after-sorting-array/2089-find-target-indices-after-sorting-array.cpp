class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lesser = 0, equal = 0;
        for (auto num : nums) num < target ? lesser++ : target == num ? equal++ : 0;
        vector<int> res(equal);
        iota(res.begin(), res.end(), lesser);
        return res;
    }
};