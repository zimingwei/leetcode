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
        ListNode dummy(0);
        dummy.next = head;
        ListNode *curr = &dummy;
        while (curr->next != NULL) {
            ListNode *next = curr->next;
            while (next->next != NULL && next->next->val == next->val) {
                next = next->next;
            }
            if (curr->next == next) { // no duplicates in between
                curr = next;
            } else {
                curr->next = next->next;
            }
        }
        return dummy.next;
    }
};
