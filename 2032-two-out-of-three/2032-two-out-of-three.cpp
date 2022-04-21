class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int arr[101][3];
        memset(arr, 0, sizeof(arr));
        for (auto ele : nums1) arr[ele][0] = 1;
        for (auto ele : nums2) arr[ele][1] = 1;
        for (auto ele : nums3) arr[ele][2] = 1;
        vector<int> res;
        for (int i = 1; i <= 100; i++) {
            int sum = arr[i][0] + arr[i][1] + arr[i][2];
            if (sum >= 2) res.push_back(i);
        }
        return res;
    }
};