class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 = 0, n = word1.size(), m = word2.size();
        string result;
        while (p1 < n || p2 < m) {
            if (p1 < n) result += word1[p1++];
            if (p2 < m) result += word2[p2++];
        }
        return result;
    }
};