class Solution {
public:
    // Time: O(mn)
    // Space: O(mn)
    // Let f[i][j] represent whether s3[0...i+j) can be formed by the
    // interleaving of s1[0...i) and s2[0...j).
    // f[i][j] = (s1[i-1] == s3[i+j-1] && f[i-1][j]) || 
    //           (s2[j-1] == s3[i+j-1] && f[i][j-1])
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }
        
        vector<vector<bool> > f(m+1, vector<bool>(n+1));
        f[0][0] = true;
        for (int i = 1; i <= m; i++) {
            f[i][0] = s1[i-1] == s3[i-1] && f[i-1][0];
        }
        for (int j = 1; j <= n; j++) {
            f[0][j] = s2[j-1] == s3[j-1] && f[0][j-1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = (s1[i-1] == s3[i+j-1] && f[i-1][j]) || 
                          (s2[j-1] == s3[i+j-1] && f[i][j-1]);
            }
        }
        return f[m][n];
    }
};
