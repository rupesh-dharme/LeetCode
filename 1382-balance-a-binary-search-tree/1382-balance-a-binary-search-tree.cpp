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
    void inorder(TreeNode* root, vector<int>& in) {
        if (!root) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        return createBST(in, 0, in.size()-1);
    }
    TreeNode* createBST(vector<int>& in, int s, int e) {
        if (s > e) return NULL;
        int m = s + (e - s)/2;
        TreeNode* root = new TreeNode(in[m]);
        root->left = createBST(in, s, m-1);
        root->right = createBST(in, m+1, e);
        return root;
    }
};