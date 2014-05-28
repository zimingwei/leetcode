class Solution {
public:
    // Let f[i][j] be the number of distinct subsequences of T[0,j] in S[0,i].
    // If S[i] != T[j], then f[i][j] = f[i-1][j]
    // If S[i] == T[j], then f[i][j] = f[i-1][j-1] + f[i-1][j]
    // Time: O(mn)
    // Space: O(n)
    int numDistinct(string S, string T) {
        int m = S.length();
        int n = T.length();
        vector<int> f(n+1, 0);
        f[0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = n; j > 0; j--) {
                if (S[i-1] == T[j-1]) {
                    f[j] += f[j-1];
                }
            }
        }
        return f[n];
    }
};
