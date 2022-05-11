class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n), b(n);
        f[0] = nums[0]; b[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            f[i] = f[i-1] * nums[i];
        }
        for (int i = n-2; i >= 0; i--) {
            b[i] = b[i+1] * nums[i];
        }
        vector<int> result(n);
        for (int i = 1; i < n-1; i++) {
            result[i] = f[i-1] * b[i+1];
        }
        result[0] = b[1]; result[n-1] = f[n-2];
        return result;
    }
};