/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    TreeNode* root;
    FindElements(TreeNode* _root) {
        root = _root;
        if (root) root->val = 0;
        create(root);
    }
    
    bool find(int target) {
        return search(target, root);
    }
    
    void create(TreeNode* root) {
        if (!root) return;
        if (root->left) {root->left->val = 2*root->val + 1; create(root->left);}
        if (root->right) {root->right->val = 2*root->val + 2; create(root->right);}
    }
    
    bool search(int target, TreeNode* root) {
        if (!root) return false;
        if (root->val == target) return true;
        return search(target, root->left) || search(target, root->right);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */