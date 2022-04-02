class Solution {
public:
    int findTheWinner(int n, int k) {
        if (k == 1) return n;
        vector<int> v(n+1);
        iota(v.begin(), v.end(), 1);
        v[n] = 1;
        // for (auto num : v) cout << num << " ";
        int ptr = 1;
        while (n > 1) {
            for (int i = 0; i < k-2; i++) {
                ptr = v[ptr];
            }
            v[ptr] = v[v[ptr]];
            ptr = v[ptr];
            // for (auto num : v) cout << num << " ";
            // cout << '\n';
            n--;
        }
        return v[ptr];
    }
};