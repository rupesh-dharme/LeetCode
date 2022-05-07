class Node {
// private:
public:
    Node* links[26];
    bool flag;
// public:
    bool contains(char ch) {
        return (links[ch - 'a'] != NULL);
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

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!node->contains(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return search(word, root);
    }
    bool search(string word, Node* node) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                bool res = false;
                for (int j = 0; j < 26; j++) {
                    if (node->links[j]) {
                        if (search(word.substr(i+1), node->links[j])) {
                            res = true;
                            break;
                        }
                    }
                }
                return res;
                // return search(word.substr(i+1), )
            }
            if (node->contains(word[i])) {
                node = node->get(word[i]);
            } else {
                return false;
            }
        }
        return node->isEnd();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */