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
    TreeNode *sortedArrayToBST(vector<int> &num, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = sortedArrayToBST(num, left, mid-1);
        node->right = sortedArrayToBST(num, mid+1, right);
        return node;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size()-1);
    }
};
