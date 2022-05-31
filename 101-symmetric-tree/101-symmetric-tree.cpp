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
    bool isSymmetric(TreeNode* root) {
        return isMirrored(root->left, root->right);
    }
    
    bool isMirrored(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val && isMirrored(left->left, right->right) && isMirrored(left->right, right->left);
    }
};

// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (not root) return true;
//         return isMirrored(root->left, root->right);
//     }
//     bool isMirrored(TreeNode* left, TreeNode* right) {
//         if (!right && !left) return true;
//         if (right && left) {
//             return right->val == left->val && isMirrored(right->left, left->right) && isMirrored(right->right, left->left);
//         }
//         return false;
//     }
// };