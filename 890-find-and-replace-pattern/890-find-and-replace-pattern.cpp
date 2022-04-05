class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (auto &word : words) {
            unordered_map<char, char> mpf, mpb;
            bool flag = true;
            for (int i = 0; i < word.size(); i++) {
                if ((mpf.find(word[i]) != mpf.end() && mpf[word[i]] != pattern[i]) || (mpb.find(pattern[i]) != mpb.end() && mpb[pattern[i]] != word[i])) {flag = false; break;}
                else {mpf[word[i]] = pattern[i]; mpb[pattern[i]] = word[i];}
            }
            if (flag) result.push_back(word);
        }
        return result;
    }
};