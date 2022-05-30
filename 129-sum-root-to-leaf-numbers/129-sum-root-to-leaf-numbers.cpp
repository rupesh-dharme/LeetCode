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
    int sumNumbers(TreeNode* root) {
        int sum = 0, num = 0;
        recurse(root, num, sum);
        return sum;
    }
    
    void recurse(TreeNode *root, int &num, int &sum) {
        if (!root->left && !root->right) {
            num *= 10;
            num += root->val;
            sum += num;
            num /= 10;
            return;
        }
        num *= 10;
        num += root->val;
        if (root->left) recurse(root->left, num, sum);
        if (root->right) recurse(root->right, num, sum);
        num /= 10;
    }
};