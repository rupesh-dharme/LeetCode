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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        auto node = root;
        while (root) {
            if (val < root->val && root->left == NULL) {root->left = new TreeNode(val); break;}
            else if (val > root->val && root->right == NULL) {root->right = new TreeNode(val); break;}
            else {
                root = val < root->val ? root->left : root->right;
            }
        }
        return node;
    }
};

// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if (!root) {
//             root = new TreeNode(val);
//             return root;
//         }
//         TreeNode* dummy = root;
//         insert(dummy, val);
//         return root;
//     }
//     void insert(TreeNode* root, int val) {
//         if (val < root->val) {
//             if (root->left) {
//                 insert(root->left, val);
//             } else {
//                 root->left = new TreeNode(val);
//                 return;
//             }
//         } else {
//             if (root->right) {
//                 insert(root->right, val);
//             } else {
//                 root->right = new TreeNode(val);
//                 return;
//             }
//         }
//     }
// };