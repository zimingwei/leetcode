class Solution {
public:
    // Let f[i] be the number of unique BST's when BST stores consecutive i values
    // If k (1 <= k <= i) is the value of root, then
    // number of unique left subBST's is f[k-1] (1 ... k-1)
    // number of unique right subBST's is f[i-k] (k+1 ... i)
    // number of unique BST's when k is the value of root is f[k-1] * f[i-k]
    // So f[i] = SUM(f[k-1] * f[i-k]) (1 <= k <= i)
    // Time: O(n^2)
    // Space: O(n)
    int numTrees(int n) {
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                f[i] += f[k-1] * f[i-k];
            }
        }
        return f[n];
    }
};
