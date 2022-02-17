class Solution {
public:
    int maxArea(vector<int>& height) {
        int width = height.size()-1;
        int l = 0, r = width;
        int mx = 0;
        while (l < r) {
            mx = max(mx, min(height[l], height[r])*width);
            height[l] < height[r] ? l++ : r--;
            width--;
        }
        return mx;
    }
};