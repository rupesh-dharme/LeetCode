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
    int minDiffInBST(TreeNode* root) {
        int mn = INT_MAX, pnode = -1;
        while (root) {
            if (!root->left) {
                if (pnode >= 0) mn = min(mn, root->val - pnode);
                pnode = root->val;
                root = root->right;
            }
            else {
                TreeNode *prev = root->left;
                while (prev->right != NULL && prev->right != root) prev = prev->right;
                if (!prev->right) {
                    prev->right = root;
                    root = root->left;
                }
                else {
                    prev->right = NULL;
                    if (pnode >= 0) mn = min(mn, root->val - pnode);
                    pnode = root->val;
                    root = root->right;
                }
            }
        }
        return mn;
    }
};