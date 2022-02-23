/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node*, Node*> clones;
        Node* copy = new Node(node->val);
        clones[node] = copy;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* temp = q.front(), *clone;
            q.pop();
            clone = clones[temp];
            for (auto neighbor : temp->neighbors) {
                Node * cloneneb;
                if (clones.find(neighbor) == clones.end()) {
                    cloneneb = new Node(neighbor->val);
                    clones[neighbor] = cloneneb;
                    q.push(neighbor);
                }
                cloneneb = clones[neighbor];
                clone->neighbors.push_back(cloneneb);
            }
        }
        return clones[node];
    }
};