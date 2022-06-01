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


// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

class Solution {
public:
    void flatten(TreeNode * root) { // morris traversal
        TreeNode *node = root;
        while (root) {
            if (!root->left) {
                root = root->right;
            }
            else {
                TreeNode *prev = root->left;
                while (prev->right) prev = prev->right;
                prev->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
        }
    }
};

// class Solution {
// public:
//     void flatten(TreeNode * root) {
//         if(root == nullptr) return;
//         flatten(root->left);
//         flatten(root->right);
//         TreeNode * p = root->right;
//         root->right = root->left;
//         root->left = nullptr;
//         while(root->right) root = root->right;
//         root->right = p;
//     }
// };

