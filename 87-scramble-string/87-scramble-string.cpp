class Solution {
private:
    unordered_map<string, bool> um;
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() < 1) return false;
        if (s1.compare(s2) == 0) return true;
        if (um.count(s1 + "#" + s2)) return um[s1 + "#" + s2];
        int n = s1.size();
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i))) || (isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i)))) {
                flag = true;
                break;
            }
        }
        um[s1 + "#" + s2] = flag;
        return flag;
    }
};