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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode temp(0);
        temp.next = head;
        ListNode *prev = &temp;
        ListNode *curr = prev->next;
        ListNode *next = curr->next;
        while (next != NULL) {
            prev->next = next;
            curr->next = next->next;
            next->next = curr;
            
            prev = curr;
            curr = curr->next;
            next = (curr != NULL) ? curr->next : NULL;
        }
        return temp.next;
    }
};
