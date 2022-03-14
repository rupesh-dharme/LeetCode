class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        string result;
        for (int i = 0; i < n; i++) {
            if (i + 2 < n && s[i+2] == '#') {
                result += 'a' + stoi(s.substr(i, 2))-1;
                i += 2;
            }
            else result += 'a' + s[i] - '1';
        }
        return result;
    }
};