class Solution {
private:
    int count;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    
    void DFS(int n, int row) {
        if (row == n) {
            count++;
            return;
        }
        
        for (int j = 0; j < n; j++) {
            bool valid = col[j] && diag1[row+j] && diag2[row-j+n];
            if (valid) {
                col[j] = diag1[row+j] = diag2[row-j+n] = false;
                DFS(n, row+1);
                col[j] = diag1[row+j] = diag2[row-j+n] = true;
            }
        }
    }
public:
    // Time: O(n!)
    // Space: O(n)
    int totalNQueens(int n) {
        count = 0;
        col = vector<bool>(n, true); // Can we put Queen in this column?
        diag1 = vector<bool>(2*n, true);
        diag2 = vector<bool>(2*n, true);
        DFS(n, 0);
        return count;
    }
};
