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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        
        queue<TreeNode*> curr, next;
        curr.push(root);
        while (!curr.empty()) {
            vector<int> level;
            while (!curr.empty()) {
                TreeNode *node = curr.front();
                curr.pop();
                level.push_back(node->val);
                if (node->left != NULL) {
                    next.push(node->left);
                }
                if (node->right != NULL) {
                    next.push(node->right);
                }
            }
            result.push_back(level);
            swap(curr, next);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
