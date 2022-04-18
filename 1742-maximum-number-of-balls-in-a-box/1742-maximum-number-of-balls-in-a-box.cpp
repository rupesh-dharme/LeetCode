class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> mp;
        for (int i = lowLimit; i <= highLimit; i++) {
            int n = i, sum = 0;
            while (n) {
                sum += n%10;
                n /= 10;
            }
            mp[sum]++;
        }
        int mx = 0;
        for (auto p : mp) {
            mx = max(mx, p.second);
        }
        return mx;
    }
};