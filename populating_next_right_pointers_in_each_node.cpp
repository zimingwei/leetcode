/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    // Time: O(n)
    // Space: O(logn)
    void connect(TreeLinkNode *root, TreeLinkNode *sibling) {
        if (root == NULL) {
            return;
        }
        root->next = sibling;
        
        connect(root->left, root->right);
        if (sibling != NULL) {
            connect(root->right, sibling->left);
        } else {
            connect(root->right, NULL);
        }
    }
public:
    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
};

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
        while (prev != NULL && prev->left != NULL) {
            TreeLinkNode *next = prev->left; // next level
            while (prev != NULL) {
                TreeLinkNode *curr = prev->left;
                curr->next = prev->right;
                curr = curr->next;
                prev = prev->next;
                curr->next = (prev == NULL) ? NULL : prev->left;
            }
            prev = next;
        }
    }
};
