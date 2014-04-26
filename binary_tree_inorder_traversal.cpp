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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode *n = root;
        while (!s.empty() || n != NULL) {
            if (n != NULL) {
                s.push(n);
                n = n->left;
            } else {
                n = s.top();
                s.pop();
                result.push_back(n->val);
                n = n->right;
            }
        }
        return result;
    }
};
