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
    void pathSum(TreeNode *root, int sum, vector<int> &path,
                 vector<vector<int> > &result) {
        if (root == NULL) {
            return;
        }
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                result.push_back(path);
            }
        }
        pathSum(root->left, sum - root->val, path, result);
        pathSum(root->right, sum - root->val, path, result);
        path.pop_back();
    }
public:
    // Time: O(n)
    // Space: O(logn)
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > result;
        pathSum(root, sum, path, result);
        return result;
    }
};
