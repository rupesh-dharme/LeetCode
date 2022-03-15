class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = word.find(ch);
        if (pos == -1) return word;
        int l = 0, r = pos;
        while (l < r) {
            swap(word[l++], word[r--]);
        }
        return word;
    }
};