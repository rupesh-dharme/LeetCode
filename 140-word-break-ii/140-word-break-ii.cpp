class Node {
private:
    Node* links[26];
    bool flag;
public:
    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    bool isEnd() {
        return flag;
    }
    void setEnd() {
        flag = true;
    }
};

class Trie {
public:
    Node* root;
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
    void addSent(unordered_set<string> &res, string &s, string str, int i, Node *node) {
        for (; i < s.size(); i++) {
            if (!node->contains(s[i])) return;
            str += s[i];
            node = node->get(s[i]);
            if (node->isEnd()) {
                addSent(res, s, str + ' ', i + 1, root);
            }
        }
        if (str.back() == ' ') str.pop_back();
        if (node->isEnd()) res.insert(str);
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for (auto word : wordDict) t.insert(word);
        unordered_set<string> st;
        t.addSent(st, s, "", 0, t.root);
        vector<string> res;
        for (auto str : st) res.push_back(str);
        return res;
    }
};