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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp, *prev;
        ListNode *dummy = new ListNode();
        prev = dummy;
        dummy->next = head;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        ListNode *start = prev->next;
        ListNode *end = start;
        for (int i = 0; i < right-left; i++) end = end->next;
        ListNode *nextToEnd = end->next;
        prev->next = end;
        prev = NULL;
        ListNode *curr = start, *next;
        while (prev != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        start->next = nextToEnd;
        return dummy->next;
    }
};