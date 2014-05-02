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
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return true;
        } else if (left != NULL && right != NULL) {
            return left->val == right->val &&
                   isSymmetric(left->left, right->right) &&
                   isSymmetric(left->right, right->left);
        } else {
            return false;
        }
    }
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        } else {
            return isSymmetric(root->left, root->right);
        }
    }
};

class Solution {
public:
    // Time: O(n)
    // Space: O(logn)
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        
        stack<TreeNode*> S;
        S.push(root->left);
        S.push(root->right);
        while (!S.empty()) {
            TreeNode *right = S.top();
            S.pop();
            TreeNode *left = S.top();
            S.pop();
            if (right == NULL && left == NULL) {
                continue;
            } else if (right != NULL && left != NULL) {
                if (right->val != left->val) {
                    return false;
                }
                S.push(left->left);
                S.push(right->right);
                S.push(left->right);
                S.push(right->left);
            } else {
                return false;
            }
        }
        return true;
    }
};
