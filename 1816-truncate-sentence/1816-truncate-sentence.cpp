class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size(), count = 0, i;
        for (i = 0; i < n; i++) {
            if (s[i] == ' ') count++;
            if (count == k) break;
        }
        return s.substr(0, i);
    }
};