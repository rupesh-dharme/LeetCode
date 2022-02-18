class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size(), ps = p.size();
        if (ps > ss) return {};
        vector<int> sv(26, 0), pv(26, 0), res;
        int l = 0, r = 0;
        for (; r < ps; r++) {
            sv[s[r]-'a']++;
            pv[p[r]-'a']++;
        }
        if (sv == pv) res.push_back(l);
        while (r < ss) {
            sv[s[r++]-'a']++;
            sv[s[l++]-'a']--;
            if (sv == pv) res.push_back(l);
        }
        return res;
    }
};