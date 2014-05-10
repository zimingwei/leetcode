class Solution {
private:
    bool valid(char c, vector<bool> &used) {
        if (c == '.') {
            return true;
        }
        if (used[c-'1']) {
            return false;
        }
        used[c-'1'] = true;
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> used(9, false);
            for (int j = 0; j < 9; j++) {
                if (!valid(board[i][j], used)) {
                    return false;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            vector<bool> used(9, false);
            for (int i = 0; i < 9; i++) {
                if (!valid(board[i][j], used)) {
                    return false;
                }
            }
        }
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                vector<bool> used(9, false);
                for (int i = r*3; i < r*3+3; i++) {
                    for (int j = c*3; j < c*3+3; j++) {
                        if (!valid(board[i][j], used)) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
