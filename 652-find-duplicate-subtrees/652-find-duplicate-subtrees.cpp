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
private:
    vector<TreeNode *> result;
    unordered_map<string, int> um;
public:
    string recurse(TreeNode *root) {
        if (!root) return "#";
        string left, right;
        left = recurse(root->left);
        right = recurse(root->right);
        string node = "left(" + left + ")root(" + to_string(root->val) + ")right(" + right +')';
        if (um[node] == 1) {
            result.push_back(root);   
        }
        um[node]++;
        return node;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        recurse(root);
        return result;
    }
};