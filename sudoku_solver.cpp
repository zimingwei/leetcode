class Solution {
private:
    bool isValid(const vector<vector<char> > &board, int x, int y) {
        for(int i = 0; i < 9; i++) {
            if (i != x && board[i][y] == board[x][y]) {
                return false;
            }
        }
        for(int j = 0; j < 9; j++) {
            if (j != y && board[x][j] == board[x][y]) {
                return false;
            }
        }
        for (int i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++) {
            for (int j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++) {
                if (i != x && j != y && board[i][j] == board[x][y]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solveSudokuHelper(vector<vector<char> > &board, int i, int j) {
        if (j >= 9) {
            return solveSudokuHelper(board, i+1, 0);
        }
        if (i == 9) {
            return true;
        }
        if (board[i][j] == '.') {
            for (int k = 0; k < 9; k++) {
                board[i][j] = '1' + k;
                if (isValid(board, i, j)) {
                    if (solveSudokuHelper(board, i, j+1)) {
                        return true;
                    }
                }
                board[i][j] = '.';
            }
        } else {
            return solveSudokuHelper(board, i, j+1);
        }
        return false;
    }
    
public:
    // Time: O(9^81)
    // Space: O(81)
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuHelper(board, 0, 0);
    }
};
