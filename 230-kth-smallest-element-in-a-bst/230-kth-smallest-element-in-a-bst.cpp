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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, res;
        while (root) {
            if (!root->left) {
                count++;
                if (count == k) {
                    res = root->val;
                }
                root = root->right;
            }
            else {
                TreeNode *prev = root->left;
                while(prev->right != NULL && prev->right != root) prev = prev->right;
                if (!prev->right) {
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = NULL;
                    count++;
                    if (count == k) {
                        res = root->val;
                    }
                    root = root->right;
                }
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         int i = 0, res;
//         traverse(root, i, k, res);
//         return res;
//     }
//     void traverse(TreeNode* root, int &i, int k, int &res) {
//         if (!root) return;
//         if (root->left) traverse(root->left, i, k, res);
//         i++;
//         if (i == k) {res = root->val; return;}
//         if (root->right) traverse(root->right, i, k, res);
//     }
// };