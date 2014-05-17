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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *prevM;
        ListNode *prev = &dummy;
        ListNode *curr = head;
        for (int i = 1; i <= n; i++) {
            if (i == m) {
                prevM = prev;
            }
            if (i > m) {
                prev->next = curr->next;
                curr->next = prevM->next;
                prevM->next = curr;
                curr = prev;
            }
            prev = curr;
            curr = curr->next;
        }
        return dummy.next;
    }
};
