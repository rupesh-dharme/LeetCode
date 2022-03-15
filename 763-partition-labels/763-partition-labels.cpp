class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> um;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            um[s[i]] = i;
        }
        vector<int> result;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, um[s[i]] + 1);
            if (i == mx - 1) result.push_back(mx);
        }
        int k = result.size();
        for (int i = k-1; i > 0; i--) {
            result[i] -= result[i-1];
        }
        return result;
    }
};