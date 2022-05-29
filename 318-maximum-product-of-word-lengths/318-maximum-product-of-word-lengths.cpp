class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string, int> um;
        for (auto &word : words) {
            int num = 0;
            for (auto ch : word) num |= (1 << (ch - 'a'));
            um[word] = num;
        }
        int mx = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((um[words[i]] & um[words[j]]) == 0) {
                    mx = max(mx, (int)(words[i].size() * words[j].size()));
                } 
            }
        }
        return mx;
    }
    // int maxProduct(vector<string>& words) {
    //     unordered_map<string, vector<int>> um;
    //     for (auto &word : words) {
    //         vector<int> v(26, 0);
    //         for (auto ch : word) v[ch - 'a'] = 1;
    //         um[word] = v;
    //     }
    //     int mx = 0;
    //     for (int i = 0; i < words.size(); i++) {
    //         for (int j = i + 1; j < words.size(); j++) {
    //             bool f = true;
    //             for (int k = 0; k < 26; k++) {
    //                 if (um[words[i]][k] == um[words[j]][k] && um[words[i]][k] == 1) {
    //                     f = false;
    //                     break;
    //                 }
    //             }
    //             if (f) {
    //                 if (mx == 0) {
    //                     mx = words[i].size() * words[j].size();
    //                 } else {
    //                     mx = max(mx, (int)(words[i].size() * words[j].size()));
    //                 }
    //             }
    //         }
    //     }
    //     return mx;
    // }
};