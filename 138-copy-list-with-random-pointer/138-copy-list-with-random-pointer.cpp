/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void crossJoin(Node *head) {
        Node *node = head;
        while (node) {
            Node *next = node->next;
            node->next = new Node(node->val);
            node->next->next = next;
            node = node->next->next;
        }
    }
    
    void attachRandom(Node *head) {
        Node *node = head;
        while (node) {
            if (node->random)
                node->next->random = node->random->next;
            else node->next->random = NULL;
            node = node->next->next;
        }
    }
    
    Node *seperate(Node *head) {
        Node *node = head, *copy = head->next, *tail = head->next;
        while (node) {
            node->next = tail->next;
            if (node->next)
                tail->next = node->next->next;
            else tail->next = NULL;
            node = node->next;
            tail = tail->next;
        }
        return copy;
    }
    
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        crossJoin(head);
        attachRandom(head);
        return seperate(head);
    }
};

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node *, Node *> um;
//         Node *node = head;
//         while (node) {
//             Node *newNode = new Node(node->val);
//             um[node] = newNode;
//             node = node->next;
//         }
//         node = head;
//         while(node) {
//             um[node]->next = um[node->next];
//             um[node]->random = um[node->random];
//             node = node->next;
//         }
//         return um[head];
//     }
// };