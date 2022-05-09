class Node {
private:
    Node* links[26];
    bool flag;
public:
    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node * root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->contains(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool isValid(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            node = node->get(word[i]);
            if (!node->isEnd()) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) {
            if (lhs.size() > rhs.size()) return true;
            else if (lhs.size() == rhs.size()) return lhs < rhs;
            return false;
        });
        Trie trie;
        for (auto &word : words) {trie.insert(word); cout << word << " ";}
        for (auto &word : words) {
            if (trie.isValid(word)) return word;
        }
        return "";
    }
};