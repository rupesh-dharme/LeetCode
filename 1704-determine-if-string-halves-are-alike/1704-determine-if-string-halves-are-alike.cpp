class Solution {
public:
    bool halvesAreAlike(string str) {
        unordered_set<char> us = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int fhalf = 0, shalf = 0, n = str.size()/2, f, s;
        for (f = 0, s = n; f < n; f++, s++) {
            if (us.find(str[f]) != us.end()) fhalf++;
            if (us.find(str[s]) != us.end()) shalf++;
        }
        return fhalf == shalf;
    }
};