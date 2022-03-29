/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> traversal;
        recurse(root, traversal);
        return traversal;
    }
    void recurse(Node* root, vector<int> &traversal) {
        if (!root) return;
        for (auto &child : root->children) recurse(child, traversal);
        traversal.push_back(root->val);
    }
};