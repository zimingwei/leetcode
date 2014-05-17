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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder,
                        int inleft, int inright, int postleft, int postright) {
        if (inleft > inright || postleft > postright) {
            return NULL;
        }
        
        int leftsize = 0;
        for (int i = inleft; i <= inright; i++) {
            if (inorder[i] == postorder[postright]) {
                break;
            }
            leftsize++;
        }
        TreeNode *node = new TreeNode(postorder[postright]);
        node->left = buildTree(inorder, postorder, inleft, inleft+leftsize-1,
                               postleft, postleft+leftsize-1);
        node->right = buildTree(inorder, postorder, inleft+leftsize+1, inright,
                                postleft+leftsize, postright-1);
        return node;
    }
public:
    // Time: O(n)
    // Space: O(logn)
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, postorder, 0, inorder.size()-1, 0, 
                         postorder.size()-1);
    }
};
