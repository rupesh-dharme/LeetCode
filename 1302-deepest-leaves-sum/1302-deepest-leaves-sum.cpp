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
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        while(true) {
            int n = q.size(), curr = 0;
            bool over = true;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    curr += node->val;
                    if (node->left) {
                        over = false;
                        q.push(node->left);
                    }
                    if (node->right) {
                        over = false;
                        q.push(node->right);
                    }
                }
            }
            if (over) return curr;
        }
    }
};