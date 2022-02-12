class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> next;
        next.push(beginWord);
        unordered_set<string> dict(wordList.begin(), wordList.end());
        int ladder = 1;
        while(!next.empty()) {
            int n = next.size();
            string word;
            for (int i = 0; i < n; i++) {
                word = next.front();
                next.pop();
                if (word == endWord) return ladder;
                for (int j = 0; j < word.size(); j++) {
                    char ch = word[j];
                    dict.erase(word);
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            next.push(word);
                        }
                    }
                    word[j] = ch;
                }
            }
            ladder++;
        }
        return 0;
    }
};