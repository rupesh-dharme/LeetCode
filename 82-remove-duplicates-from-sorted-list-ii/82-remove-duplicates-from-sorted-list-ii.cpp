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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* next = head->next;
        int val = head->val;
        if (val != next->val) {
            head->next = deleteDuplicates(next);
            return head;
        }
        else {
            
            while (next && next->val == val) {
                next = next->next;
            }
            return deleteDuplicates(next);
        }
    }
};