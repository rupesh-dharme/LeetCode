class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss, tt;
        for (auto ch : s) {
            if (ch == '#') {
                if (ss.size()!=0) {
                    ss = ss.substr(0, ss.size()-1);
                }
            } else {
                ss += ch;
            }
        }
        for (auto ch : t) {
            if (ch == '#') {
                if (tt.size()!=0) {
                    tt = tt.substr(0, tt.size()-1);
                }
            } else {
                tt += ch;
            }
        }
        return (ss == tt);
    }
};