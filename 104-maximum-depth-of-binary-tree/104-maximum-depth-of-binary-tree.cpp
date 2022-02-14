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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        int n, depth = 0;
        q.push(root);
        while (!q.empty()) {
            n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            depth++;
        }
        return depth;
    }
};

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root) return 0;
//         return 1 + max(maxDepth(root->left), maxDepth(root->right));
//     }
// };