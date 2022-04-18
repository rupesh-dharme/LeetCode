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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* last = list2, * ptr = new ListNode(), * temp;
        ptr->next = list1;
        while (last->next) last = last->next;
        b -= a;
        while (a--) ptr = ptr->next;
        temp = ptr->next;
        ptr->next = list2;
        while (b--) temp = temp->next;
        last->next = temp->next;
        return list1;
    }
};