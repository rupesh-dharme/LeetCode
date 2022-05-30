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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        int lvl = -1;
        recurse(root, 0, lvl, res);
        return res;
    }
    
    void recurse(TreeNode *root, int cur, int &lvl, vector<int> &res) {
        if (!root) return;
        if (cur > lvl) {
            res.push_back(root->val);
            lvl = cur;
        }
        recurse(root->right, cur + 1, lvl, res);
        recurse(root->left, cur + 1, lvl, res);
    }
};