/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size()) {
            TreeNode *node = q.front(); q.pop();
            if (!node) tree += "#,";
            else tree += (to_string(node->val) + ',');
            
            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << tree;
        return tree.substr(0, tree.size()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream tree(data);
        string str;
        getline(tree, str, ',');
        if (str == "#") return NULL;
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (q.size()) {
            TreeNode *node = q.front(); q.pop();
            getline(tree, str, ',');
            if (str == "#") {
                node->left = NULL;
            } else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(tree, str, ',');
            if (str == "#") {
                node->right = NULL;
            } else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));