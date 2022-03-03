class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        unordered_map<char, int> um = {{'L', -1}, {'R', 1}, {'U', -1}, {'D', 1}};
        int m = s.size();
        vector<int> answer(m);
        for (int j = 0; j < m; j++) {
            int steps = 0, r = startPos[0], c = startPos[1];
            for (int i = j; i < m; i++) {
                if (s[i] == 'L' or s[i] == 'R') {
                    c += um[s[i]];
                } else {
                    r += um[s[i]];
                }
                if (r >= 0 && r < n && c >= 0 && c < n) steps++;
                else break;
            }
            answer[j] = steps;
        }
        return answer;
    }
};