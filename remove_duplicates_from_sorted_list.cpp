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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        
        ListNode *prev = head;
        ListNode *curr = head->next;
        while (curr != NULL) {
            if (prev->val == curr->val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};
