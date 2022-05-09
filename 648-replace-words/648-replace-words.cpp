class Node {
private:
    Node *links[26];
    bool flag;
public:
    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) {
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
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->contains(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    Node *getRoot() {
        return root;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        sort(dictionary.begin(), dictionary.end());
        for (auto &word : dictionary) trie.insert(word);
        istringstream iss(sentence);
        string result;
        string word;
        while (iss >> word) {
            string pref;
            bool found = false;
            Node *node = trie.getRoot();
            for (int i = 0; i < word.size(); i++) {
                if (!node->contains(word[i])) {
                    break;
                } else {
                    node = node->get(word[i]);
                    pref += word[i];
                    if (node->isEnd()) {
                        found = true;
                        break;
                    }
                }
            }
            result += " ";
            if (found) {
                result += pref;
            } else {
                result += word;
            }
        }
        return result.substr(1, result.size() - 1);
    }
};