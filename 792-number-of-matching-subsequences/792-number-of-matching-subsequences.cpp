class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> index[26];
        for (int i = 0; i < s.size(); i++) index[s[i]-'a'].push_back(i);
        int count = 0;
        
        for (auto &word : words) {
            int prev = -1;
            bool found = true;
            for (auto ch : word) {
                vector<int> &indices = index[ch-'a'];
                auto it = upper_bound(indices.begin(), indices.end(), prev);
                if (it == indices.end()) {
                    found = false;
                    break;
                }
                prev = *it;
            }
            if (found) count++;
        }
        
        return count;
    }
};