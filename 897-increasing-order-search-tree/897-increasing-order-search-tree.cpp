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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode();
        TreeNode* ans = dummy;
        recurse(root, dummy);
        return ans->right;
    }
    void recurse(TreeNode* root, TreeNode* &dummy) {
        if (!root) return;
        recurse(root->left, dummy);
        dummy->right = new TreeNode(root->val);
        dummy = dummy->right;
        recurse(root->right, dummy);
    }
};