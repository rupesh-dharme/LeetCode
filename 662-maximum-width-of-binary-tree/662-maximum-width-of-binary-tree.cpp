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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int width = 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        while (q.size()) {
            int n = q.size();
            int start = q.front().second;
            int first, last;
            
            for (int i = 0; i < n; i++) {
                auto [node, id] = q.front(); q.pop();
                id -= start;
                if (i == 0) first = id;
                if (i == n-1) last = id;
                
                if (node->left) q.push({node->left, id*2 + 1});
                if (node->right) q.push({node->right, id*2 + 2});
            }
            
            width = max(width, last - first + 1);
        }
        return width;
    }
};

// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;
//         queue<pair<TreeNode*,unsigned long long int>>q;
//         q.push({root,1});TreeNode* temp;
//         int size;int res=0;int d;
//         while(!q.empty()){
//             size=q.size();
//             if (size == 1){
//                 q.push({q.front().first,1});
//                 q.pop();
//             }
//             d= q.back().second-q.front().second+1;
//             res=max(res,d);
//             while(size--){
//                 if(q.front().first->left) q.push({q.front().first->left, (q.front().second*2)});
//                 if(q.front().first->right) q.push({q.front().first->right, ((q.front().second*2)+1)});
//                 q.pop();
//             }
//         }
//         return res;
//     }
// };