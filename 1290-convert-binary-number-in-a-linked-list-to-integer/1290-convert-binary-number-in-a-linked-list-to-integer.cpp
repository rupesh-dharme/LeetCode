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
    int getDecimalValue(ListNode* head) {
        int decimal = 0;
        ListNode *node = head;
        while (node) {
            decimal <<= 1;
            decimal += node->val;
            node = node->next;
        }
        return decimal;
    }
};

// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         int res = 0;
//         while (head) {
//             res <<= 1;
//             res += head->val;
//             head = head->next;
//         }
//         return res;
//     }
// };