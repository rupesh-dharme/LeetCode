class Solution {
public:
    bool isAnagram(string s, string t) {
        int ss = s.size(), ts = t.size();
        if (ss != ts) return false;
        vector<int> sv(26, 0), tv(26, 0);
        for (int i = 0; i < ss; i++) {
            sv[s[i]-'a']++;
            tv[t[i]-'a']++;
        }
        return (sv==tv);
    }
};