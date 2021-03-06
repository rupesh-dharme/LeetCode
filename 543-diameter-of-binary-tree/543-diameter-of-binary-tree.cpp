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
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        recurse(root, mx);
        return mx;
    }
    
    int recurse(TreeNode *root, int &mx) {
        if (!root) return 0;
        int l = recurse(root->left, mx);
        int r = recurse(root->right, mx);
        mx = max(mx, l + r);
        return 1 + max(l, r);
    }
};

// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         int diameter = 0;
//         solve(root, diameter);
//         return diameter;
//     }
    
//     int solve(TreeNode* root, int &diameter) {
//         if (!root) return 0;
        
//         int l = solve(root->left, diameter);
//         int r = solve(root->right, diameter);
        
//         int temp = max(l, r) + 1;
//         diameter = max(diameter, l + r);
//         return temp;
//     }
// };