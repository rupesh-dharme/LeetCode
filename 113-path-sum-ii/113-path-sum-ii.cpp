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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> path;
        solve(root, targetSum, path, res);
        return res;
    }
    void solve(TreeNode *root, int &target, vector<int> &path, vector<vector<int>> &res) {
        path.push_back(root->val);
        target -= root->val;
        if (!root->left && !root->right) {
            if (target == 0) res.push_back(path);
        } else {
            if (root->left) solve(root->left, target, path, res);
            if (root->right) solve(root->right, target, path, res);
        }
        path.pop_back();
        target += root->val;
    }
};