class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        if (n == 1) return 0;
        vector<int> security;
        for (int i = 0; i < n; i++) {
            int temp = count(bank[i].begin(), bank[i].end(), '1');
            if (temp) security.push_back(temp);
        }
        int l = 0, r = 1, m = security.size(), result = 0;
        while (r < m) {
            result += security[l++]*security[r++];
        }
        return result;
    }
};