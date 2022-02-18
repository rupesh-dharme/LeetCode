class Solution {
public:
    string interpret(string c) {
        string res;
        int n = c.size();
        for (int l = 0; l < n; l++) {
            if (c[l] == '(') {
                int r = l;
                while (r < n) {
                    if (c[r] != ')') {
                        r++; continue;
                    }
                    else break;
                }
                if (r-l > 1) res += "al";
                else res += 'o';
                l = r;
            }
            else res += c[l];
        }
        return res;
    }
};