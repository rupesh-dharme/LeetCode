class Solution {
public:
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int countVowelStrings(int n) {
        int result = 0;
        string str;
        recurse(str, result, 0, n);
        return result;
    }
    void recurse(string &str, int &result, int i, int n) {
        
        if (str.size() == n) {
            result++;
            return;
        }
        if (i == 5) return;
        str += vowels[i];
        recurse(str, result, i, n);
        str.pop_back();
        recurse(str, result, i+1, n);
    }
};