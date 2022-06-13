class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> um;
        int width = INT_MAX, n = cards.size();
        for (int i = 0; i < n; i++) {
            int card = cards[i];
            if (um.count(card)) {
                width = min(width, i - um[card] + 1);
            }
            um[card] = i;
        }
        return width == INT_MAX ? -1 : width;
    }
};