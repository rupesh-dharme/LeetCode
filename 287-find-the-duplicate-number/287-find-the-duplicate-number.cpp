class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (nums[slow] == nums[fast]) break;
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        // cout << slow << " " << fast << endl;
        // return nums[nums[slow]];
    }
};

// class Solution { // with extra space
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> visited(n+1, 0);
//         int i = 0;
//         visited[0] = 1;
//         while (!visited[nums[i]]) {
//             visited[nums[i]] = 1;
//             i = nums[i];
//         }
//         return nums[i];
//     }
// };

// class Solution { // TLE
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n-1; i++) {
//             for (int j = i+1; j < n; j++) {
//                 if (nums[i] == nums[j]) return nums[i];
//             }
//         }
//         return -1;
//     }
// };