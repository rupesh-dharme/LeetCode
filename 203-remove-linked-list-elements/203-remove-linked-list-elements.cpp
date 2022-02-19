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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummy = new ListNode();
        dummy->next = head;
        ListNode* ans = dummy;
        while (dummy) {
            while(dummy->next && dummy->next->val != val) {
                dummy = dummy->next;
            }
            if (dummy->next) {
                dummy->next = dummy->next->next;
            }
            else {
                dummy = dummy->next;
            }
        }
        return ans->next;
    }
};