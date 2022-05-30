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
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        maxPath(root, mx);
        return mx;
    }
    
    int maxPath(TreeNode *root, int &mx) {
        if (!root) return 0;
        
        int l = maxPath(root->left, mx);
        int r = maxPath(root->right, mx);
        
        mx = max(mx, l + r + root->val);
        
        return max(l, r) + root->val >= 0 ? max(l, r) + root->val : 0;
    }
};