class Solution {
public:
    // Time: O(n^2)
    // Space: O(n^2)
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        int first = 0;
        int last = n - 1;
        int num = 1;
        
        while (first < last) {
            for (int j = first; j < last; j++) {
                matrix[first][j] = num++;
            }
            for (int i = first; i < last; i++) {
                matrix[i][last] = num++;
            }
            for (int j = last; j > first; j--) {
                matrix[last][j] = num++;
            }
            for (int i = last; i > first; i--) {
                matrix[i][first] = num++;
            }
            first++;
            last--;
        }
        if (first == last) {
            matrix[first][last] = num;
        }
        return matrix;
    }
};
