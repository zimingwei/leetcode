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
    // Time: O(n)
    // Space: O(logn)
    int getHeight(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        if (left < 0 || right < 0 || abs(left-right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    } 
public:
    bool isBalanced(TreeNode *root) {
        return getHeight(root) >= 0;
    }
};
