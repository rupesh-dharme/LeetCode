class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        recurse(s, 0, path, result);
        return result;
    }
    void recurse(string &s, int index, vector<string> &path, vector<vector<string>> &result) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (palindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                recurse(s, i+1, path, result);
                path.pop_back();
            }
        }
    }
    bool palindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};