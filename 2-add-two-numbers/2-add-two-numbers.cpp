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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* curr = new ListNode();
        curr->next = res;
        int c = 0;
        while(l1 && l2) {
            int val = l1->val + l2->val + c;
            curr = curr->next;
            c = val/10;
            val %= 10;
            curr->val = val;
            curr->next = new ListNode();
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int val = l1->val + c;
            c = val/10;
            curr = curr->next;
            val %= 10;
            curr->val = val;
            curr->next = new ListNode();
            l1 = l1->next;
        }
        while (l2) {
            int val = l2->val + c;
            c = val/10;
            val %= 10;
            curr = curr->next;
            curr->val = val;
            curr->next = new ListNode();
            l2 = l2->next;
        }
        if (c) curr->next = new ListNode(c);
        else curr->next = NULL;
        return res;
    }
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummy=new ListNode(0);
//         ListNode* head=dummy;
//         int sum=0;
//         while(l1 || l2 || sum){
//             if(l1){
//                sum+=l1->val;
//                 l1=l1->next;
//             }
//             if(l2){
//                 sum+=l2->val;
//                 l2=l2->next;
//             }
            
//             ListNode* temp=new ListNode(sum%10);
//             head->next=temp;
//             head=temp;
//             sum/=10;
//         }
//         return dummy->next;
//     }
// };