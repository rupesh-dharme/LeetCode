class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> powers;
        for (int i = 1; i <= 1e7; i *= 3) powers.push_back(i);
        int l = 0, r = powers.size() - 1;
        while (r >= 0) {
            while (l < r) {
                int m = l + (r - l + 1) / 2;
                if (powers[m] <= n) l = m;
                else r = m - 1;
            }
            n -= powers[l];
            if (n == 0) return true;
            l = 0; r--;
        }
        return false;
    }
};