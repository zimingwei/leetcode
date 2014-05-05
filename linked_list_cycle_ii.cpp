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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                int C = 0; // Cycle length
                do {
                    C++;
                    fast = fast->next;
                } while (fast != slow);
                
                fast = slow = head;
                while (C--) {
                    fast = fast->next;
                }
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
                }
        }
        return NULL;
    }
};
