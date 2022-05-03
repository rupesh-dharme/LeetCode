class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN, n = nums.size();
        bool f = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) f = true;
            if (f) mn = min(mn, nums[i]);
        }
        f = false;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] > nums[i+1]) f = true;
            if (f) mx = max(mx, nums[i]);
        }
        int s = n, e = -1;
        for (int i = 0; i < n; i++) if (nums[i] > mn) {s = i; break;}
        for (int i = n-1; i >= 0; i--) if (nums[i] < mx) {e = i; break;}
        return s > e ? 0 : e - s + 1;
    }
    
    // int findUnsortedSubarray(vector<int>& nums) {
    //     vector<int> sorted(nums);
    //     sort(sorted.begin(), sorted.end());
    //     int st = nums.size(), en = -1, n = nums.size();
    //     for (int i = 0; i < n; i++) {
    //         if (sorted[i] != nums[i]) st == n ? st = i : en = i;
    //     }
    //     return st > en ? 0 : en - st + 1;
    // }
};