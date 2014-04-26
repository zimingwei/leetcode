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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (root != NULL) {
            s.push(root);
        }
        while (!s.empty()) {
            TreeNode *n = s.top();
            s.pop();
            result.push_back(n->val);
            if (n->right != NULL) {
                s.push(n->right);
            }
            if (n->left != NULL) {
                s.push(n->left);
            }
        }
        return result;
    }
};
