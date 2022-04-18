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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        int binary = 0;        
        solve(root, binary, sum);
        return sum;
    }
    
    void solve(TreeNode* root, int &binary, int &sum) {
        if (!root) return;
        if (!root->left && !root->right) {
            binary <<= 1;
            binary |= root->val;
            sum += binary;
            binary >>= 1;
            return;
        }
        binary <<= 1;
        binary |= root->val;
        solve(root->left, binary, sum);
        solve(root->right, binary, sum);
        binary >>= 1;
    }
};