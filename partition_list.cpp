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
    // Time: O(n)
    // Space: O(1)
    ListNode *partition(ListNode *head, int x) {
        ListNode left(0);
        ListNode right(0);
        ListNode *l = &left;
        ListNode *r = &right;
        
        for (ListNode *p = head; p != NULL; p = p->next) {
            if (p->val < x) {
                l->next = p;
                l = l->next;
            } else {
                r->next = p;
                r = r->next;
            }
        }
        l->next = right.next;
        r->next = NULL;
        return left.next;
    }
};
