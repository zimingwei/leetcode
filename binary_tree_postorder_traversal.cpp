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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<TreeNode*> S;
        S.push(root);
        TreeNode *prev = root;
        while (!S.empty()) {
            TreeNode *curr = S.top();
            // leaf node or has been visited
            if ((curr->left == NULL && curr->right == NULL) || 
                curr->left == prev || curr->right == prev) {
                result.push_back(curr->val);
                prev = curr;
                S.pop();
            } else {
                if (curr->right != NULL) {
                    S.push(curr->right);
                }
                if (curr->left != NULL) {
                    S.push(curr->left);
                }
            }
        }
        return result;
    }
};
