class Solution {
public:
    string toLowerCase(string s) {
        for (auto& ch : s) {
            int i = ch - 'A';
            if (i >= 0 && i < 26) ch+=32;
        }
        return s;
    }
};