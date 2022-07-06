class Solution {
public:
    vector<int> v;
    Solution(): v(31, -1) {}
    int fib(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (v[n] != -1) return v[n];
        else {
            return v[n] = fib(n-1) + fib(n-2);
        }
    }
};