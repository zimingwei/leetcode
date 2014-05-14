/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *sortedListToBST(ListNode *&list, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode *left = sortedListToBST(list, start, mid-1);
        TreeNode *node = new TreeNode(list->val);
        node->left = left;
        list = list->next;
        node->right = sortedListToBST(list, mid+1, end);
        return node;
    }
public:
    // Time: O(n)
    // Space: O(logn)
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        for (ListNode *p = head; p != NULL; p = p->next) {
            len++;
        }
        return sortedListToBST(head, 0, len-1);
    }
};
