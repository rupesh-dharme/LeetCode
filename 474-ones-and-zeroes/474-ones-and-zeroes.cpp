class Solution {
private:
    int mx = 0, count = 0;
    vector<vector<vector<int>>> dp;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.assign(strs.size(), vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        return recurse(strs, 0, m, n);
    }
    
    int recurse(vector<string> &strs, int i, int m, int n) {
        if (m < 0 || n < 0) return 0;
        if (m == 0 && n == 0) return  0;
        if (i == strs.size()) {
            mx = max(mx, count);
            return 0;
        }
        if (dp[i][m][n] != -1) return dp[i][m][n];
        int l = recurse(strs, i+1, m, n), r = 0;
        int os = 0, zs = 0;
        for (auto ch : strs[i]) ch == '1' ? os++ : zs++;
        if (zs <= m && os <= n) {
            count++;
            r = 1 + recurse(strs, i + 1, m - zs, n - os);
            count--;
        }
        return dp[i][m][n] = max(l, r);
    }
};