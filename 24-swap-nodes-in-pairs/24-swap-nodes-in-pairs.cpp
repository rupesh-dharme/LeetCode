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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
    }
};

// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(!head || !head->next) return head;
//         ListNode* p = head,* c = p->next;
//         head = p->next;
//         while (c && c->next) {
//             ListNode * temp = c->next;
//             p->next = c->next->next;
//             c->next = p;
//             p = temp;
//             c = temp->next;
//         }
//         if (!c) {
//             return head;
//         }
//         // p->next = NULL;
//         c->next = p;
//         return head;
//     }
// };