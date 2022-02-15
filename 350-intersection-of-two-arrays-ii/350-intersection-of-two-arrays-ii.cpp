class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = 0, n2 = 0, nums1_size = nums1.size(), nums2_size = nums2.size();
        while (n1 < nums1_size && n2 < nums2_size) {
            if (nums1[n1] == nums2[n2]) {
                res.push_back(nums1[n1]);
                n1++; n2++;
            }
            else nums1[n1] > nums2[n2] ? n2++ : n1++;
        }
        return res;
    }
};