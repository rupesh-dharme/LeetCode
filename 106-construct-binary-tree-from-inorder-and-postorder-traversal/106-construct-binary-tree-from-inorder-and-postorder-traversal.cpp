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
    TreeNode *build(vector<int> &in, vector<int> &post, int is, int ie, int ps, int pe, unordered_map<int, int> &inmap) {
        if (is > ie || ps > pe) return NULL;
        
        TreeNode *root = new TreeNode(post[pe]);
        
        int idx = inmap[post[pe]];
        
        root->left = build(in, post, is, idx - 1, ps, ps + idx - is - 1, inmap);
        root->right = build(in, post, idx + 1, ie, ps + idx - is, pe - 1, inmap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int, int> inmap;
        int n = in.size();
        for (int i = 0; i < n; i++) inmap[in[i]] = i;
        
        TreeNode *root = build(in, post, 0, n-1, 0, n-1, inmap);
        return root;
    }
};