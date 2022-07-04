class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) return n;
        vector<int> result(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                result[i] = result[i-1]+1;
            }
        }
        for (int i = n-1; i > 0; i--) {
            if (ratings[i-1] > ratings[i]) {
                result[i-1] = max(result[i] + 1, result[i-1]);
            }
        }
        int sum = 0;
        for (auto num : result) sum += num;
        return sum;
    }
};