class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> um = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.size(), result = 0;
        for (int i = 0; i < n; i++) {
            if (i+1 < n && um[s[i]] < um[s[i+1]]) {
                result += um[s[i + 1]] - um[s[i]];
                i++;
            } else {
                result += um[s[i]];
            }
        }
        return result;
    }
};