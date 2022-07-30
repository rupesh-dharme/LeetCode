class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int b[26] = {0};
        for (auto &word : words2) {
            int temp[26] = {0};
            for (auto ch : word) temp[ch - 'a']++;
            for (int i = 0; i < 26; i++) b[i] = max(b[i], temp[i]);
        }
        vector<string> result;
        for (auto &word : words1) {
            int a[26] = {0};
            for (auto ch : word) a[ch - 'a']++;
            bool flag = true;
            for (int i = 0; i < 26; i++) if (a[i] < b[i]) {flag = false; break;}
            if (flag) result.push_back(word);
        }
        return result;
    }
};