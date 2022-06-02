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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) root = val < root->val ? root->left : root->right;
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (!root) return NULL;
//         if (root->val == val) return root;
//         if (root->val < val) return searchBST(root->right, val);
//         else return searchBST(root->left, val);
//     }
// };

// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root->val == val) return root;
//         if (root->left) {
//             TreeNode* node = searchBST(root->left,val);
//             if (node) return node;
//         }
//         if (root->right) {
//             TreeNode* node = searchBST(root->right, val);
//             if (node) return node;
//         }
//         return NULL;
//     }
// };