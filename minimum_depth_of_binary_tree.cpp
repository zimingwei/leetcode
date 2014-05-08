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
    // Space: O(n)
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root, 1));
        while (!Q.empty()) {
            TreeNode *node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            // leaf node
            if (node->left == NULL && node->right == NULL) {
                return depth;
            }
            if (node->left != NULL) {
                Q.push(make_pair(node->left, depth+1));
            }
            if (node->right != NULL) {
                Q.push(make_pair(node->right, depth+1));
            }
        }
    }
};
