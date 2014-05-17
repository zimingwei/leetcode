class Solution {
private:
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    
    void DFS(int row, vector<string> &board, vector<vector<string> > &result) {
        int n = board.size();
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int j = 0; j < n; j++) {
            bool valid = col[j] && diag1[row+j] && diag2[row-j+n];
            if (valid) {
                col[j] = diag1[row+j] = diag2[row-j+n] = false;
                board[row][j] = 'Q';
                DFS(row+1, board, result);
                col[j] = diag1[row+j] = diag2[row-j+n] = true;
                board[row][j] = '.';
            }
        }
    }

public:
    // Time: O(n!)
    // Space: O(n)
    vector<vector<string> > solveNQueens(int n) {
        col = vector<bool>(n, true); // Can we put Queen in this column?
        diag1 = vector<bool>(2*n, true);
        diag2 = vector<bool>(2*n, true);
        vector<string> board(n, string(n, '.'));
        vector<vector<string> > result;
        DFS(0, board, result);
        return result;
    }
};
