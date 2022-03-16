class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> um;
        for (auto &ch : s) um[ch]++;
        int freq = um[s[0]];
        for (auto [ch, count] : um) if (count != freq) return false;
        return true;
    }
};