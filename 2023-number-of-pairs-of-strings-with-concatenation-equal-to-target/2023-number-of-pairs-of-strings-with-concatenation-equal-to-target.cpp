class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (nums[i] + nums[j] == target) count++;
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int numOfPairs(vector<string>& nums, string target) {
//         int n = nums.size();
//         unordered_map<string, vector<int>> mp;
//         for (int i = 0; i < n; i++) {
//             mp[nums[i]].push_back(i);
//         }
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             string num = nums[i];
//             int len = num.size();
//             if (target.substr(0, len) == num) {
//                 string last = target.substr(len, target.size() - len);
//                 if (mp.find(last) != mp.end()) {
//                     if (binary_search(mp[last].begin(), mp[last].end(), i)) count += mp[last].size()-1;
//                     else count += mp[last].size();
//                 }
//             }
//             else if (target.substr(target.size()-len-1, len) == num) {
//                 string first = target.substr(0, target.size() - len);
//                 if (mp.find(first) != mp.end()) {
//                     if (binary_search(mp[first].begin(), mp[first].end(), i)) count += mp[first].size()-1;
//                     else count += mp[first].size();
//                 }
//             }
//         }
//         return count;
//     }
// };