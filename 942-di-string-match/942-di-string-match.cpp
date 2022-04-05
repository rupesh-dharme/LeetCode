class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int l = 0, r = n;
        vector<int> result;
        if (s[0] == 'I') result.push_back(l++);
        else result.push_back(r--);
        for (int i = 0; i < n-1; i++) {
            if (s[i] == 'I' and s[i+1] == 'D') result.push_back(r--);
            else if (s[i] == 'I' and s[i+1] == 'I') result.push_back(l++);
            else if (s[i] == 'D' and s[i+1] == 'I') result.push_back(l++);
            else result.push_back(r--);
        }
        if (s[n-1] == 'I') result.push_back(l);
        else result.push_back(r);
        return result;
    }
};