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
        int i = 0;
        return create(preorder, i, INT_MAX);
    }
    TreeNode* create(vector<int>& pre, int & i, int upper) {
        if (i >= pre.size() || pre[i] > upper) return nullptr;
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = create(pre, i, root->val);
        root->right = create(pre, i, upper);
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         return create(preorder, 0, preorder.size()-1);
//     }
//     TreeNode* create(vector<int>& pre, int s, int e) {
//         if (s > e) return NULL;
//         if (s == e) {
//             TreeNode* root = new TreeNode(pre[s]);
//             return root;
//         }
//         int mid = s+1;
//         for (; mid <= e; mid++) {
//             if (pre[mid] > pre[s]) break;
//         }
//         TreeNode* root = new TreeNode(pre[s]);
//         root->left = create(pre, s+1, mid-1);
//         root->right = create(pre, mid, e);
//         return root;
//     }
// };