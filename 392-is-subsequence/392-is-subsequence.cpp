class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sn = s.size(), tn = t.size();
        if (sn > tn) return false;
        int sp = 0, tp = 0;
        while (tp < tn) {
            if (t[tp] == s[sp]) sp++;
            tp++;
        }
        if (sp == sn) return true;
        return  false;
    }
};