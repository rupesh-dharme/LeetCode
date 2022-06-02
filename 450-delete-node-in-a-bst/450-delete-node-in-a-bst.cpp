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
class Solution {
public:
    TreeNode *solve(TreeNode *root) {
        if (!root->left || !root->right) {
            return root->left ? root->left : root->right;
        }
        auto left = root->left, right = root->right;
        TreeNode *temp = left;
        while (temp->right) temp = temp->right;
        temp->right = right;
        delete root;
        return left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        TreeNode *node = root;
        if (root->val == key) return solve(root);
        while (root) {
            if (key < root->val) {
                if (root->left && root->left->val == key) root->left = solve(root->left);
                else root = root->left;
            }
            else {
                if (root->right && root->right->val == key) root->right = solve(root->right);
                else root = root->right;
            }
        }
        return node;
    }
};