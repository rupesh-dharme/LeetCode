/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        ListNode *node = head;
        for (int i = 1; i < k; i++) { // k-1 jumps
            node = node->next;
            if (!node) return head;
        }
        ListNode *nextHead = reverseKGroup(node->next, k);
        ListNode *p = NULL, *c = head, *n, *lastsNext = node->next;
        while (c != lastsNext) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head->next = nextHead;
        return p;
    }
};