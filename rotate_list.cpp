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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) {
            return head;
        }
        
        int len = 1;
        ListNode *p = head;
        while (p->next != NULL) {
            len++;
            p = p->next;
        }
        k = len - k % len;
        p->next = head;
        for (int i = 0; i < k; i++) {
            p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};
