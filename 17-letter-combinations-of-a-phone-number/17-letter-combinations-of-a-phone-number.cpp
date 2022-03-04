class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> um = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> result;
        if (digits.size() == 0) return result;
        recurse(digits, 0, digits.size(), result, um);
        return result;
    }
    void recurse(string& digits, int ind, int n, vector<string>& result, unordered_map<int, string>& um) {
        if (ind == n) {
            result.push_back(digits);
            return;
        }
        for (int i = 0; i < um[digits[ind]-'0'].size(); i++) {
            char temp = digits[ind];
            digits[ind] = um[digits[ind]-'0'][i];
            recurse(digits, ind+1, n, result, um);
            digits[ind]= temp;
        }
    }
};