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
    int maxAncestorDiff(TreeNode* root) {
        return recurse(root, root->val, root->val);
    }
    
    int recurse(TreeNode* root, int mx, int mn) {
        if (!root) return (mx - mn);
        
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        
        int l = recurse(root->left, mx, mn);
        int r = recurse(root->right, mx, mn);
        
        return max(l, r);
    }
};