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
    bool isValidBST(TreeNode* root, long long l = (long long)INT_MIN-1, long long r = (long long)INT_MAX+1) {
        if (!root) return true;
        if (!(l < root->val) || !(root->val < r)) return false;
        return isValidBST(root->left, l, root->val) && isValidBST(root->right, root->val, r);
    }
};

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         TreeNode* prev = NULL;
//         return validate(root, prev);
//     }
//     bool validate(TreeNode* node, TreeNode* &prev) {
//         if (node == NULL) return true;
//         if (!validate(node->left, prev)) return false;
//         if (prev != NULL && prev->val >= node->val) return false;
//         prev = node;
//         return validate(node->right, prev);
//     }
// };