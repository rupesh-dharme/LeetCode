class Node {
private:
    Node *links[26];
    int sum;
    int value;
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
    int getSum() {
        return sum;
    }
    int getVal() {
        return value;
    }
    void setSum(int val) {
        sum = val;
    }
    void setVal(int val) {
        value = val;
    }
};

class Trie {
private:
    Node *root;
    unordered_map<string, int> mp;
public:
    Trie() {
        root = new Node();
    }
    void insert(string &word, int val) {
        Node *node = root;
        int addSum;
        if (mp.count(word)) {addSum = val - mp[word]; mp[word] = val;}
        else {mp[word] = val; addSum = val;}
        for (int i = 0; i < word.size(); i++) {
            if (!node->contains(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
            // node->sum += val;
            node->setSum(node->getSum() + addSum);
        }
        // node->value = val;
        node->setVal(val);
    }
    int getSum(string &word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if(!node->contains(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        return node->getSum();
    }
};

class MapSum {
private:
    Trie trie;
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        trie.insert(key, val);
    }
    
    int sum(string prefix) {
        return trie.getSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */