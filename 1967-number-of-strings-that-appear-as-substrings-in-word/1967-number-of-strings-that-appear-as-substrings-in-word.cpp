class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (auto& pattern : patterns) if (word.find(pattern) != -1) count++;
        return count;
    }
};

// class Solution {
// public:
//     int numOfStrings(vector<string>& patterns, string word) {
//         unordered_map<string, int> um;
//         for (int i = 0; i < word.size(); i++) {
//             string temp;
//             for (int j = i; j < word.size(); j++) {
//                 temp += word[j];
//                 um[temp] = 1;
//             }
//         }
//         int count = 0;
//         for (auto& pattern : patterns) if (um.find(pattern) != um.end()) count++;
//         return count;
//     }
// };