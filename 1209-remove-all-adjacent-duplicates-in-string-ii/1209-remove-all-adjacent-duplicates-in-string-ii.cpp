class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;
        for (auto ch : s) {
            if (stack.size() && stack.top().first == ch) {
                stack.top().second++;
                if (stack.top().second == k) stack.pop();
                continue;
            }
            else {
                stack.push({ch, 1});
            }
        }
        string result;
        while (stack.size()) {
            auto [ch, count] = stack.top(); stack.pop();
            while (count--) {
                result += ch;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};