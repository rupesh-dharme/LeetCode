class Solution {
public:
    bool isPal(string& s, int r, int l = 0) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (auto& word : words) if (isPal(word, word.size()-1)) return word;
        return "";
    }
};