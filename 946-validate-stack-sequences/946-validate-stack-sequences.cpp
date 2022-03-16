class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        for (auto num : pushed) {
            stk.push(num);
            while (!stk.empty() && stk.top() == popped[i]) {
                stk.pop();
                i++;
            }
        }
        return i == popped.size();
    }
};