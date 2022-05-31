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
    TreeNode *build(vector<int> &pre, vector<int> &in, int ps, int pe, int is, int ie, unordered_map<int, int> &inmap) {
        if (ps > pe || is > ie) return NULL;
        TreeNode *root = new TreeNode(pre[ps]);
        
        int idx = inmap[pre[ps]];
        
        root->left = build(pre, in, ps + 1, ps + idx - is, is, idx - 1, inmap);
        root->right = build(pre, in, ps + idx - is + 1, pe, idx + 1, ie, inmap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inmap;
        for (int i = 0; i < n; i++) inmap[inorder[i]] = i;
        TreeNode *res = build(preorder, inorder, 0, n-1, 0, n-1, inmap);
        return res;
    }
};