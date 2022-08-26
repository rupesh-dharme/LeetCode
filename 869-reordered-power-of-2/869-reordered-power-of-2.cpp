class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(), num.end());
        do {
            if (num[0] != '0') {
                int perm = stoi(num);
                if ((perm & (perm - 1)) == 0) return true;
            }
        } while (next_permutation(num.begin(), num.end()));
        return false;
    }
};