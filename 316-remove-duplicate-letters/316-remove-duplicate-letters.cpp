class Solution {
public:
    string removeDuplicateLetters(string s) {
            vector<int> cand(26, 0);
            vector<bool> visited(26, false);
            for (char c : s)
                cand[c-'a']++;
            string result = "0";
            for (char c : s) {
                cand[c-'a']--;
                if (visited[c-'a']) continue;
                while (c < result.back() && cand[result.back()-'a']) {
                    visited[result.back()-'a'] = false;
                    result.pop_back();
                }
                result += c;
                visited[c-'a'] = true;
            }
            return result.substr(1);
    }
};