class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sv(26), tv(26);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            sv[s[i]-'a']++;
            tv[t[i]-'a']++;
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += abs(sv[i] - tv[i]);
        }
        return result/2;
    }
};