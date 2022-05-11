class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto &str : strs) {
            vector<int> freq(26, 0);
            for (auto ch : str) freq[ch - 'a']++;
            string key;
            for (int i = 0; i < 26; i++) {
                key += (to_string(freq[i]) + '#');
            }
            if (mp.count(key)) mp[key].push_back(str);
            else mp[key] = {str};
        }
        vector<vector<string>> result;
        for (auto &[key, v] : mp) {
            result.push_back(v);
        }
        return result;
    }
};