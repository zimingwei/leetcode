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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        
        stack<TreeNode*> curr, next;
        bool odd = true;
        curr.push(root);
        while (!curr.empty()) {
            vector<int> level;
            while (!curr.empty()) {
                TreeNode *node = curr.top();
                curr.pop();
                if (node != NULL) {
                    level.push_back(node->val);
                    if (odd) {
                        next.push(node->left);
                        next.push(node->right);
                    } else {
                        next.push(node->right);
                        next.push(node->left);
                    }
                }
            }
            if (level.size() > 0) {
                result.push_back(level);
            }
            odd = !odd;
            swap(curr, next);
        }
        return result;
    }
};
