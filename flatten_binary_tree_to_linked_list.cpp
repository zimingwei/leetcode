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
public:
    // Time: O(n)
    // Space: O(logn)
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        flatten(root->left);
        flatten(root->right);
        
        if (root->left == NULL) {
            return;
        }
        
        // Insert flattened left tree between root and root->right
        TreeNode *p = root->left;
        while (p->right != NULL) {
            p = p->right;
        }
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};
