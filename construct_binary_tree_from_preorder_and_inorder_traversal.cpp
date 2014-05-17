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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder,
                        int preleft, int preright, int inleft, int inright) {
        if (preleft > preright || inleft > inright) {
            return NULL;
        }
        
        int leftsize = 0;
        for (int i = inleft; i <= inright; i++) {
            if (preorder[preleft] == inorder[i]) {
                break;
            }
            leftsize++;
        }
        TreeNode *node = new TreeNode(preorder[preleft]);
        node->left = buildTree(preorder, inorder, preleft+1, preleft+leftsize,
                               inleft, inleft+leftsize-1);
        node->right = buildTree(preorder, inorder, preleft+leftsize+1, preright,
                                inleft+leftsize+1, inright);
        return node;
    }
public:
    // Time: O(n)
    // Space: O(logn)
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, inorder, 0, preorder.size()-1, 0,
                         inorder.size()-1);
    }
};
