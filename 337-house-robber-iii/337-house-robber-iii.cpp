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
private:
    unordered_map<TreeNode *, int> um;
public:
    int rob(TreeNode* root) {
        return robMax(root);
    }
    int robMax(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (um.count(root)) return um[root];
        int one = root->val;
        if (root->left) {
            one += robMax(root->left->left);
            one += robMax(root->left->right);
        }
        if (root->right) {
            one += robMax(root->right->left);
            one += robMax(root->right->right);
        }
        int two = robMax(root->left) + robMax(root->right);
        um[root] = max(one, two);
        return max(one, two);
    }
};