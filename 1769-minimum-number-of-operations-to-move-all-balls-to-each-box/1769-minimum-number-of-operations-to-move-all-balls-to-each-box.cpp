class Solution {
public:
    vector<int> minOperations(string boxes) {
        set<int> st;
        vector<int> result;
        int n = boxes.size();
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') st.insert(i);
        }
        for (int i = 0; i < n; i++) {
            int operations = 0;
            for (auto idx : st) {
                operations += abs(idx - i);
            }
            result.push_back(operations);
        }
        return result;
    }
};