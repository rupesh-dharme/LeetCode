class WordFilter {
   private:
    unordered_map<string, int> hashMap;

   public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int wordSize = word.size();
            for (int j = 1; j <= wordSize; j++) {
                string p = word.substr(0, j);
                for (int k = 0; k < wordSize; k++) {
                    string s = word.substr(k, wordSize);
                    hashMap[p + "|" + s] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = prefix + "|" + suffix;
        return hashMap[s] - 1;
    }
};

// class Node { // TLE
// public:
//     Node *links[26];
//     vector<int> words;
//     bool contains(char ch) {
//         return links[ch - 'a'] != NULL;
//     }
//     Node *get(char ch) {
//         return links[ch - 'a'];
//     }
//     void put(char ch, Node *node) {
//         links[ch - 'a'] = node;
//     }
// };

// class Trie {
// public:
//     Node *root;
//     Trie() {
//         root = new Node();
//     }
//     void insert(string word, bool suffix = false, int idx = 0) {
//         Node *node = root;
//         for (int i = 0; i < word.size(); i++) {
//             if (!node->contains(word[i])) node->put(word[i], new Node());
//             node = node->get(word[i]);
//             node->words.push_back(idx);
//         }
//     }
//     vector<int> search(string word) {
//         Node *node = root;
//         for (int i = 0; i < word.size(); i++) {
//             if (!node->contains(word[i])) return {};
//             node = node->get(word[i]);
//         }
//         return node->words;
//     }
// };

// class WordFilter {
// private:
//     Trie forward, backward;
//     unordered_map<string, int> index;
// public:
//     WordFilter(vector<string>& words) {
//         for (int i = 0; i < words.size(); i++) {
//             string word = words[i];
//             index[word] = i;
//             forward.insert(word, false, i);
//             reverse(word.begin(), word.end());
//             backward.insert(word, true, i);
//         }
//     }
    
//     int f(string prefix, string suffix) {
//         vector<int> f = forward.search(prefix);
//         reverse(suffix.begin(), suffix.end());
//         vector<int> b = backward.search(suffix);
//         vector<int> i;
//         unordered_map<int, int> w;
//         for (auto word : f) w[word] = 1;
//         for (auto word : b) if (w[word] == 1) i.push_back(word);
//         sort(i.begin(), i.end());
//         if (i.size()) {
//             return i.back();
//         } else return -1;
//     }
// };

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */