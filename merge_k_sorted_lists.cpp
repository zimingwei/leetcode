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

    ListNode *mergeKListsHelper(vector<ListNode *> &lists, int left, int right) {
        if (left >= right) {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        return mergeTwoLists(mergeKListsHelper(lists, left, mid), 
                             mergeKListsHelper(lists, mid+1, right));
    }
    
public:
    // Time: O(nklogk)
    // Space: O(logk)
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        return mergeKListsHelper(lists, 0, lists.size()-1);
    }
};
