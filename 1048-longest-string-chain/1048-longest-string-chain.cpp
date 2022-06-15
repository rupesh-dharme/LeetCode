class Solution {
public:
    bool predecessor(string a, string b) {
        int n = a.size(), i = 0, j = 0;
        while (i < n) {
            if (a[i] != b[j]) {
                j++;
                while (i < n) {
                    if (a[i] != b[j]) return false;
                    i++; j++;
                }
            }
            i++; j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (words[i].size() == words[j].size() + 1 && predecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};