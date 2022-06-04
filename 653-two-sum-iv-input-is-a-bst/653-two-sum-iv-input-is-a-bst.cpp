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

class BSTIterator {
private:
    stack<TreeNode *> stk;
    bool reverse = false;
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    int next() {
        TreeNode *node = stk.top(); stk.pop();
        reverse ? pushAll(node->left) : pushAll(node->right);
        return node->val;
    }
    bool hasNext() {
        return !stk.empty();
    }
    void pushAll(TreeNode *node) {
        if (!reverse) {
            while (node) {
                stk.push(node);
                node = node->left;
            }
        } else {
            while (node) {
                stk.push(node);
                node = node->right;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator left(root, false);
        BSTIterator right(root, true);
        int l = left.next();
        int r = right.next();
        while (l < r) {
            if (l + r == k) return true;
            else if (l + r < k) l = left.next();
            else r = right.next();
        }
        return false;
    }
};

// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         unordered_set<int> set;
//         return dfs(root, set, k);
//     }
    
//     bool dfs(TreeNode* root, unordered_set<int>& set, int k){
//         if(root == NULL)return false;
//         if(set.count(k - root->val))return true;
//         set.insert(root->val);
//         return dfs(root->left, set, k) || dfs(root->right, set, k);
//     }
// };