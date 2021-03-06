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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        while (root) {
            if (!root->left) {
                in.push_back(root->val);
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
                    in.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return in;
    }
};

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> inorder;
//         if (!root) return inorder;
//         while (root) {
//             if (!root->left) {
//                 inorder.push_back(root->val);
//                 root = root->right;
//             }
//             else {
//                 TreeNode *prev = root->left;
//                 while (prev->right != NULL && prev->right != root) prev = prev->right;
//                 if (prev->right) {
//                     prev->right = NULL;
//                     inorder.push_back(root->val);
//                     root = root->right;
//                 }
//                 else {
//                     prev->right = root;
//                     root = root->left;
//                 }
//             }
//         }
//         return inorder;
//     }
// };

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root, vector<int> res = {}) {
//         if (!root) return res;
//         stack<TreeNode*> stk;
//         while (root || !stk.empty()) {
//             while (root) {
//                 stk.push(root);
//                 root = root->left;
//             }
//             root = stk.top(); stk.pop();
//             res.push_back(root->val);
//             root = root->right;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         inorder(root, result);
//         return result;
//     }
//     void inorder(TreeNode* root, vector<int>& result) {
//         if (!root) return;
//         inorder(root->left, result);
//         result.push_back(root->val);
//         inorder(root->right, result);
//     }
// };