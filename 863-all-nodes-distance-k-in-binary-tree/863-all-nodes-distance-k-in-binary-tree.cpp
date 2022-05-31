/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentof) {
        if (!root) return;
        if (root->left) {
            parentof[root->left] = root;
            markParents(root->left, parentof);
        }
        if (root->right) {
            parentof[root->right] = root;
            markParents(root->right, parentof);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, TreeNode *> parentof;
        markParents(root, parentof);
        
        unordered_set<TreeNode *> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited.insert(target);
        int lvl = 0;
        while (q.size()) {
            int n = q.size();
            if (k == lvl++) break;
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front(); q.pop();
                if (parentof.find(node) != parentof.end() && !visited.count(parentof[node])) {
                    visited.insert(parentof[node]);
                    q.push(parentof[node]);
                }
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
            }
        }
        vector<int> res;
        while (q.size()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};