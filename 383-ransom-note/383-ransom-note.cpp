class Solution {
public:
    bool canConstruct(string note, string mag) {
        int r = note.size(), m = mag.size(), i = 0;
        if (r > m) return false;
        vector<int> rv(26, 0), mv(26, 0);
        for (; i < r; i++) {
            rv[note[i]-'a']++;
            mv[mag[i]-'a']++;
        }
        for (; i < m; i++) {
            mv[mag[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (rv[i] > mv[i]) return false;
        }
        return true;
    }
};