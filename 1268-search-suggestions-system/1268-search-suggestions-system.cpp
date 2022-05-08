class Node {
// private:
public:
    Node* links[26];
    vector<string> suggestions;
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
    vector<string> getSugg() {
        return suggestions;
    }
};

class Trie {
private:
    Node* root;
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
            if (node->suggestions.size() < 3) node->suggestions.push_back(word);
        }
    }
    Node* getRoot() {
        return root;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string word) {
        Trie trie;
        Node* node = trie.getRoot();
        vector<vector<string>> result;
        sort(products.begin(), products.end());
        for (auto product : products) trie.insert(product);
        for (int i = 0; i < word.size(); ++i) {
            if (!node->contains(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
            result.push_back(node->suggestions);
            // if (!node->contains(word[i])) {
            //     result.push_back({});
            //     continue;
            // } else {
            //     node = node->get(word[i]);
            //     result.push_back(node->suggestions);
            // }
        }
        return result;
    }
};