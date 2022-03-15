class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(), l = 1, r = n-1, coins = 0;
        sort(piles.rbegin(), piles.rend());
        while (l < r) {
            coins += piles[l];
            l += 2;
            r -= 1;
        }
        return coins;
    }
};