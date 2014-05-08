/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        root->next = NULL;
        TreeLinkNode *prev = root; // previous level
        while (prev != NULL) {
            // first node in next level
            TreeLinkNode *next = NULL;
            TreeLinkNode *curr = NULL;
            while (prev != NULL) {
                if (next == NULL) {
                    next = (prev->left != NULL) ? prev->left : prev->right; 
                }
                if (prev->left != NULL) {
                    if (curr != NULL) {
                        curr->next = prev->left;
                    }
                    curr = prev->left;
                }
                if (prev->right != NULL) {
                    if (curr != NULL) {
                        curr->next = prev->right;
                    }
                    curr = prev->right;
                }
                prev = prev->next;
            }
            prev = next;
        }
    }
};
