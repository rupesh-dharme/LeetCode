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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return res;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()) {
            while (node) {
                s.push(node);
                node = node->left;
            }
            node = s.top(); s.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};

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