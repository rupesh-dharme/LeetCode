class Node {
private:
    Node *links[2];
public:
    bool contains(int bit) {
        return links[bit] != NULL;
    }
    void put(int bit, Node *node) {
        links[bit] = node;
    }
    Node *get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node *node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->contains(bit)) node->put(bit, new Node());
            node = node->get(bit);
        }
    }
    int maxXor(int num) {
        Node *node = root;
        int mx = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->contains(1-bit)) {
                mx = mx | (1 << i);
                node = node->get(1-bit);
            } else {
                node = node->get(bit);
            }
        }
        return mx;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (auto num : nums) {
            trie.insert(num);
        }
        int result = 0;
        for (auto num : nums) {
            result = max(result, trie.maxXor(num));
        }
        return result;
    }
};