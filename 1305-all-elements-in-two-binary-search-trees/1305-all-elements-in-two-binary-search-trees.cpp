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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1, in2;
        inorder(root1, in1);
        inorder(root2, in2);
        int l1 = 0, l2 = 0;
        vector<int> res;
        while (l1 < in1.size() && l2 < in2.size()) {
            in1[l1] < in2[l2] ? res.push_back(in1[l1++]) : res.push_back(in2[l2++]);
        }
        while (l1 < in1.size()) res.push_back(in1[l1++]);
        while (l2 < in2.size()) res.push_back(in2[l2++]);
        return res;
    }
};