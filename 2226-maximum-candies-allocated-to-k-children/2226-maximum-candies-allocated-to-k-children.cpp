class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = 1e7;
        while (l < r) {
            int m = l + (r - l + 1)/2;
            long long sum = 0;
            for (auto candy : candies) sum += candy/m;
            if (sum < k) {
                r = m - 1;
            } else if (sum >= k) {
                l = m;
            }
        }
        return l;
    }
};