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
    void detect(TreeNode *curr, TreeNode *prev, TreeNode *&first, 
                TreeNode *&second) {
        if (prev != NULL && prev->val > curr->val) {
            if (first == NULL) {
                first = prev;
            }
            second = curr;
        }
    }

public:
    // Time: O(n)
    // Space: O(1)
    void recoverTree(TreeNode *root) {
        TreeNode *curr = root;
        TreeNode *prev = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        
        while (curr != NULL) {
            if (curr->left == NULL) {
                detect(curr, prev, first, second);
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right != NULL && node->right != curr) {
                    node = node->right;
                }
                if (node->right == NULL) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    detect(curr, prev, first, second);
                    node->right = NULL;
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};
