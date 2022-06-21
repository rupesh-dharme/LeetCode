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
    ListNode *reverse(ListNode *head) {
        ListNode *p = NULL, *c = head, *n;
        while (c) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return head;
        auto slow = head, fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        auto start = head, mid = slow->next;
        while (start && mid) {
            if (start->val != mid->val) return false;
            start = start->next;
            mid = mid->next;
        }
        return true;
    }
};