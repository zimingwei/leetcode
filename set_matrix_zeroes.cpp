class Solution {
public:
    // Time: O(m*n)
    // Space: O(m+n)
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (row[i]) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (col[j]) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
public:
    // Time: O(m*n)
    // Space: O(1)
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        bool first_row = false;
        bool first_col = false;
        
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_col = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                first_row = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_row) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (first_col) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
