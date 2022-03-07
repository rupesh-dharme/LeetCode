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
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* curr = head;
        while (curr) {
            v.push_back(curr->val); 
            curr = curr->next;
        }
        int n = v.size();
        int mx = INT_MIN;
        for (int l = 0, r = n-1; l < r; l++, r--) {
            mx = max(mx, v[l] + v[r]);
        }
        return mx;
    }
};