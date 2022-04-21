class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0, n = position.size();
        for (auto coin : position) {
            if (coin % 2) odd++;
            else even++;
        }
        return min(odd, even);
    }
};