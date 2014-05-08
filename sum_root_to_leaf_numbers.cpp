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
    void DFS(TreeNode *node, int num, int &sum) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            sum += num * 10 + node->val;
        }
        DFS(node->left, num*10 + node->val, sum);
        DFS(node->right, num*10 + node->val, sum);
    }
public:
    // Time: O(n)
    // Space: O(logn)
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        DFS(root, 0, sum);
        return sum;
    }
};
