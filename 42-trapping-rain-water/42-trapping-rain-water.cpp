class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1, lmax = 0, rmax = 0, water = 0;
        
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] >= lmax) lmax = height[l];
                else water += (lmax - height[l]);
                l++;
            } else {
                if (height[r] >= rmax) rmax = height[r];
                else water += (rmax - height[r]);
                r--;
            }
        }
        
        return water;
    }
};

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> left(n), right(n);
        
//         for (int i = 0; i < n; i++) left[i] = i == 0 ? height[i] : max(left[i-1], height[i]);
//         for (int i = n-1; i >= 0; i--) right[i] = i == n-1 ? height[i] : max(right[i+1], height[i]);
        
//         int water = 0;
//         for (int i = 0; i < n; i++) {
//             water += min(left[i], right[i]) - height[i];
//         }
        
//         return water;
//     }
// };