int mod = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> stk;
        int n = arr.size();
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            if (stk.empty()) left[i] = i + 1;
            else if (arr[stk.top()] <= arr[i])
                left[i] = i - stk.top();
            else {
                while (stk.size() && arr[stk.top()] > arr[i]) stk.pop();
                if (stk.empty()) left[i] = i + 1;
                else left[i] = i - stk.top();
            }
            stk.push(i);
        }
        while (stk.size()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            if (stk.empty()) right[i] = n - i;
            else if (arr[stk.top()] < arr[i])
                right[i] = stk.top() - i;
            else {
                while (stk.size() && arr[stk.top()] >= arr[i]) stk.pop();
                if (stk.empty()) right[i] = n - i;
                else right[i] = stk.top() - i;
            }
            stk.push(i);
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long)arr[i] * (left[i] * right[i]);
            res %= mod;
        }
        return res % mod;
    }
};