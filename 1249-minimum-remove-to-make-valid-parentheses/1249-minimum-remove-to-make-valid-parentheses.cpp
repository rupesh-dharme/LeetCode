class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result;
        int count = 0;
        for (auto& ch: s) {
            if (isalpha(ch)) {
                result += ch;
            }
            else {
                if (ch == '(') count++;
                else if (ch == ')' and count - 1 < 0) continue;
                else count--;
                result += ch;
            }
        }
        while (count--) {
            result.erase(result.rfind('('), 1);
        }
        
        return result;
    }
};