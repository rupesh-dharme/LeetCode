class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> us;
        int ans = 0;
        for (auto roll : rolls) {
            us.insert(roll);
            if (us.size() == k) {
                ans++;
                us.clear();
            }
        }
        return 1 + ans;
    }
};