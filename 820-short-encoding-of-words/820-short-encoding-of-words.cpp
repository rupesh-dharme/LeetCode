class Node {
public:
    Node *links[26];
    bool end;
    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
};

class Trie {
public:
    Node *root;
    int encoding;
    Trie() {
        root = new Node();
        encoding = 0;
    }
    void insert(string word) {
        Node *node = root;
        for (int i = word.size()-1; i >= 0; i--) {
            if (!node->contains(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
            if (node->end) {
                node->end = false;
                encoding -= word.size()-i + 1; // +1 for '#'
            }
        }
        node->end = true;
        encoding += word.size() + 1;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });
        Trie trie;
        for (auto word : words) {
            trie.insert(word);
        }
        return trie.encoding;
    }
};