class Solution {
public:
    // Let P[i][j] be whether s[i][j] is a polindrome.
    // P[i][j] = (s[i] == s[j]) && P[i+1][j-1]
    // Let F[i] be the minimum cuts needed of s[0...i]
    // F[i] = min{f[j] + 1} when s[(j+1)...i] is a palindrome.
    // Time: O(n^2)
    // Space: O(n^2)
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> P(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                P[i][j] = (s[i] == s[j]) && (j - i < 2 || P[i+1][j-1]);
            }
        }
        vector<int> f(n, n);
        for (int i = 0; i < n; i++) {
            if (P[0][i]) {
                f[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (P[j+1][i]) {
                        f[i] = min(f[i], f[j]+1);
                    }
                }
            }
        }
        return f[n-1];
    }
};
