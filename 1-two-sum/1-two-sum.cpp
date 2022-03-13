class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (um.find(target-nums[i]) != um.end()) return {um[target - nums[i]], i};
            else um[nums[i]] = i;
        }
        return {-1, -1};
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> hash;
//         for (int i = 0; i < nums.size(); i++) {
//             if (hash.find(target - nums[i]) != hash.end()) {
//                 return {hash[target - nums[i]], i};
//             }
//             else hash[nums[i]] = i;
//         }
//         return {0, 0};
//     }
// };