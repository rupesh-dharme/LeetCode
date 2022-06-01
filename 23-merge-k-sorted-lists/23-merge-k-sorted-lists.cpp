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

class Compare {
public:
    bool operator() (ListNode *lhs, ListNode *rhs) {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        if (!pq.size()) return NULL;
        ListNode *res = pq.top(); pq.pop();
        ListNode *tail = res;
        if (tail->next) {
            pq.push(tail->next);
        }
        while (pq.size()) {
            tail->next = pq.top(); pq.pop();
            tail = tail->next;
            if (tail->next) pq.push(tail->next);
        }
        return res;
    }
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     int n = lists.size();
    //     if (n==0) return NULL;
    //     if (n==1) return lists[0];
    //     ListNode* res = new ListNode();
    //     ListNode* curr = res;
    //     while (true) {
    //         int nxt = 0;
    //         for (int i = 1; i < n; i++) {
    //             if ( !lists[nxt] || lists[i] && (lists[i]->val < lists[nxt]->val)) {
    //                 nxt = i;
    //             }
    //         }
    //         if (!lists[nxt]) break;
    //         curr->next = new ListNode(lists[nxt]->val);
    //         curr = curr->next;
    //         lists[nxt] = lists[nxt]->next;
    //     } 
    //     return res->next;
    // }
};