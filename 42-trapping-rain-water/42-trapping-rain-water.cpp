class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        
        for (int i = 0; i < n; i++) left[i] = i == 0 ? height[i] : max(left[i-1], height[i]);
        for (int i = n-1; i >= 0; i--) right[i] = i == n-1 ? height[i] : max(right[i+1], height[i]);
        
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(left[i], right[i]) - height[i];
        }
        
        return water;
    }
};