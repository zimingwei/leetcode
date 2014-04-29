/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Time: O(m+n)
    // Space: O(1)
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode temp(0);
        ListNode *p = &temp;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 != NULL) {
            p->next = l1;
        } else {
            p->next = l2;
        }
        return temp.next;
    }
};
