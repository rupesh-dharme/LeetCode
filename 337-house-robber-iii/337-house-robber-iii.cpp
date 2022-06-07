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
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (um.count(root)) return um[root];
        int one = root->val;
        if (root->left) {
            one += rob(root->left->left);
            one += rob(root->left->right);
        }
        if (root->right) {
            one += rob(root->right->left);
            one += rob(root->right->right);
        }
        int two = rob(root->left) + rob(root->right);
        um[root] = max(one, two);
        return max(one, two);
    }
};