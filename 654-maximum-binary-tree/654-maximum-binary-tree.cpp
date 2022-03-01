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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recurse(nums, 0, nums.size()-1);
    }
    TreeNode* recurse(vector<int>& nums , int l, int r) {
        if (l > r) return NULL;
        int ind = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] >= nums[ind]) {
                ind = i;
            } 
        }
        TreeNode* curr = new TreeNode(nums[ind]);
        curr->left = recurse(nums, l, ind-1);
        curr->right = recurse(nums, ind+1, r);
        return curr;
    }
};