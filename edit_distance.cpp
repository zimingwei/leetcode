class Solution {
public:
    // Let f[i][j] be the minimum number of steps to convert 
    // word1[0,i] (...x) to word2[0,j] (...y)
    // if x == y, then f[i][j] = f[i-1][j-1]
    // if x != y, 
    //     if we insert y for word1, then f[i][j] = f[i][j-1] + 1
    //     if we delete x for word1, then f[i][j] = f[i-1][j] + 1
    //     if we replace x with y for word1, then f[i][j] = f[i-1][j-1] + 1
    //     f[i][j] is the min of the three situations.
    // Time: O(mn)
    // Space: O(mn)
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> f(m+1, vector<int>(n+1));
        
        for (int i = 0; i <= m; i++) {
            f[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            f[0][j] = j;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    f[i][j] = f[i-1][j-1];
                } else {
                    f[i][j] = min(min(f[i-1][j-1], f[i][j-1]), f[i-1][j]) + 1;
                }
            }
        }
        return f[m][n];
    }
};
