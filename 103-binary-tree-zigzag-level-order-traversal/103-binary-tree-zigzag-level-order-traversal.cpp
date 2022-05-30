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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        bool ltor = true;
        while (q.size()) {
            int n = q.size();
            vector<int> v(n);
            for (int i = ltor ? 0 : n-1; 0 <= i && i < n; ltor ? i++ : i--) {
                TreeNode *node = q.front(); q.pop();
                v[i] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(v);
            ltor = !ltor;
        }
        return res;
    }
};