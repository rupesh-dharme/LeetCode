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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* one, * two, * dummy, * temp;
        int i = k;
        dummy = new ListNode();
        dummy ->next = head;
        while (i--) dummy = dummy->next;
        one = dummy;
        temp = one;
        dummy = new ListNode();
        dummy->next = head;
        while (temp) {
            temp = temp->next;
            dummy = dummy->next;
        }
        two = dummy;
        swap(one->val, two->val);
        return head;
    }
};