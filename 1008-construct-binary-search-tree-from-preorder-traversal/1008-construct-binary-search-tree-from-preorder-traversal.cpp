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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(preorder, 0, preorder.size()-1);
    }
    TreeNode* create(vector<int>& pre, int s, int e) {
        if (s > e) return NULL;
        if (s == e) {
            TreeNode* root = new TreeNode(pre[s]);
            return root;
        }
        int s2 = s+1;
        for (; s2 <= e; s2++) {
            if (pre[s2] > pre[s]) break;
        }
        TreeNode* root = new TreeNode(pre[s]);
        root->left = create(pre, s+1, s2-1);
        root->right = create(pre, s2, e);
        return root;
    }
};