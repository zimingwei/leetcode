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
    // Time: O(n^2)
    // Space: O(1)
    ListNode *insertionSortList(ListNode *head) {
        ListNode helper(INT_MIN); // dummy node for the head of new sorted list
        ListNode *curr = head;
        while (curr != NULL) {
            ListNode *next = curr->next;
            ListNode *pos = &helper;
            while (pos->next != NULL && pos->next->val < curr->val) {
                pos = pos->next;
            }
            curr->next = pos->next;
            pos->next = curr;
            curr = next;
        }
        return helper.next;
    }
};
