class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {swap(nums1, nums2); return;}
        int ptr1 = m-1, ptr2 = n-1, ptr = m+n-1;
        while (ptr2 >= 0) {
            if (ptr1 >= 0 && nums1[ptr1] > nums2[ptr2]) {
                nums1[ptr--] = nums1[ptr1--];
            } else {
                nums1[ptr--] = nums2[ptr2--];
            }
        }
    }
};

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int>temp;
//         int l = 0, r = 0;
//         while (l < m && r < n) {
//             if (nums1[l] <= nums2[r]) temp.push_back(nums1[l++]);
//             else temp.push_back(nums2[r++]);
//         }
//         if (l == m) {
//             while(r < n) temp.push_back(nums2[r++]);
//         } else {
//             while(l < m) temp.push_back(nums1[l++]);
//         }
//         for (int i = 0; i < m+n; i++) {
//             nums1[i] = temp[i];
//         }
//     }
// };