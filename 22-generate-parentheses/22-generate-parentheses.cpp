class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s(2*n, ' ');
        vector<string> result;
        recurse(s, 0, n, result, 0);
        return result;
    }
    void recurse(string& s, int i, int n, vector<string>& result, int count) {
        if (i > 2*n || count < 0) return;
        if (i == 2*n) {
            if (count == 0) {
                result.push_back(s);
            }
            return;
        }
        s[i] = '(';
        recurse(s, i+1, n, result, count+1);
        s[i] = ')';
        recurse(s, i+1, n, result, count-1);
    }
};