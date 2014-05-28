/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    // [begin, end], return begin as prev in next K Group
    ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end) {
        ListNode *end_next = end->next;
        ListNode *curr = begin->next;
        while (curr != end_next) {
            ListNode *next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        begin->next = end_next;
        return begin;
    }
    
public:
    // Time: O(n)
    // Space: O(1)
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2) {
            return head;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *end = head;
        while (end != NULL) {
            for (int i = 1; i < k && end != NULL; i++) {
                end = end->next;
            }
            if (end == NULL) {
                break;
            }
            prev = reverse(prev, prev->next, end);
            end = prev->next;
        }
        return dummy.next;
    }
};
