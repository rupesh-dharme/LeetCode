/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* f = head, *s = head;
        bool moved = false;
        if (f && f->next) {
            s = s->next;
            f = f->next->next;
            moved = true;
        }
        while (f && f->next && f!= s) {
            s = s->next;
            f = f->next->next;
            moved = true;
        }
        if (f == s && moved) {
            return true;
        }
        return false;
    }
};