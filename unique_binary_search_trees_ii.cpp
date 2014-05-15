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
    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> trees;
        if (start > end) {
            trees.push_back(NULL);
            return trees;
        }
        
        for (int k = start; k <= end; k++) {
            vector<TreeNode *> leftTrees = generateTrees(start, k-1);
            vector<TreeNode *> rightTrees = generateTrees(k+1, end);
            for (int i = 0; i < leftTrees.size(); i++) {
                for (int j = 0; j < rightTrees.size(); j++) {
                    TreeNode *node = new TreeNode(k);
                    node->left = leftTrees[i];
                    node->right = rightTrees[j];
                    trees.push_back(node);
                }
            }
        }
        return trees;
    }
public:
    // Time: O(?)
    // Space: O(?)
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
};
