class Solution {
public:
    bool isPowerOfThree(int n) {
        // int largest = pow(3, floor(log(INT_MAX) / log(3)));
        // cout << largest << endl;
        int largest = 1162261467;
        return n > 0 && largest % n == 0;
    }
};