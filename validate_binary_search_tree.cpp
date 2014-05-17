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
    bool isValidBST(TreeNode *root, int lower, int upper) {
        if (root == NULL) {
            return true;
        }
        return root->val > lower && root->val < upper &&
               isValidBST(root->left, lower, root->val) &&
               isValidBST(root->right, root->val, upper);
    }
public:
    // Time: O(n)
    // Space: O(logn)
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
