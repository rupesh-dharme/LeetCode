class Solution {
public:
    int wateringPlants(vector<int>& p, int c) {
        int n = p.size();
        if (n == 0) return 0;
        int d = 1, ic = c;
        for (int i = 0; i < n; i++) {
            if (p[i] > c) {
                d += 2*(i-1) + 2;
                c = ic;
            }
            d++;
            c -= p[i];
        }
        return --d;
    }
};