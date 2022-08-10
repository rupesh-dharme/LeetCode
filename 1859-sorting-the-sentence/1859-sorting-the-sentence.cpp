class Solution {
public:
    string sortSentence(string s) {
        vector<string> order(9, " ");
        int prev = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if ('1' <= s[i] && s[i] <= '9') {
                order[s[i] - '1'] = s.substr(prev, i - prev);
                prev = i + 2; // +1 for space
            }
        }
        string result;
        for (auto word : order) if (word != " ") result += (word + ' ');
        return result.substr(0, result.size() - 1);
    }
};

// class Solution {
// public:
//     string sortSentence(string s) {
//         vector<string> strings;
//         istringstream iss(s);
//         string word;
//         while (iss >> word) {
//             word = word.back() + word.substr(0, word.size() - 1);
//             strings.push_back(word);
//         }
//         sort(strings.begin(), strings.end());
//         string ans = strings[0].substr(1, strings[0].size() - 1);
//         for (int i = 1; i < strings.size(); i++) {
//             ans += " ";
//             ans += strings[i].substr(1, strings[i].size()-1);
//         }
//         return ans;
//     }
// };